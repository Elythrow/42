/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:18:43 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 12:10:38 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_arguments(t_table *table, int ac, char **av)
{
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->required_meals = ft_atoi(av[5]);
	else
		table->required_meals = -1;
	if (table->philo_count <= 0 || table->philo_count > 200
		|| table->time_to_die <= 0
		|| table->time_to_eat <= 0
		|| table->time_to_sleep <= 0
		|| (ac == 6 && table->required_meals <= 0))
		return (FAILURE);
	return (SUCCESS);
}

int	init_forks(t_table *table)
{
	int	i;
	
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if (!table->forks)
		return (FAILURE);
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}

static	t_philosopher *create_philosopher(t_table *table, int id)
{
	t_philosopher	*philo;
	
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->id = id + 1;
	philo->meals_eaten = 0;
	philo->last_meal_time = table->start_time;
	philo->is_eating = false;
	philo->table = table;
	philo->left_fork = &table->forks[id];
	philo->right_fork = &table->forks[(id + 1) % table->philo_count];
	if (pthread_mutex_init(&philo->meal_lock, NULL) != 0)
	{
		free(philo);
		return (NULL);
	}
	
	return (philo);
}

int	init_philosophers(t_table *table)
{
	int	i;
	
	table->philosophers = malloc(sizeof(t_philosopher *) * table->philo_count);
	if (!table->philosophers)
		return (FAILURE);
		
	i = 0;
	while (i < table->philo_count)
	{
		table->philosophers[i] = create_philosopher(table, i);
		if (!table->philosophers[i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*table;
	
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (parse_arguments(table, ac, av) == FAILURE)
	{
		free(table);
		return (NULL);
	}
	table->simulation_stop = false;
	table->start_time = get_time_ms();
	if (pthread_mutex_init(&table->print_lock, NULL) != 0
		|| pthread_mutex_init(&table->death_lock, NULL) != 0)
	{
		free(table);
		return (NULL);
	}
	if (init_forks(table) == FAILURE || init_philosophers(table) == FAILURE)
	{
		cleanup_table(table);
		return (NULL);
	}
	return (table);
}
