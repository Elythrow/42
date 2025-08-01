/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:59 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 12:11:06 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_threads(t_table *table)
{
	int	i;
	
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_create(&table->philosophers[i]->thread_id, NULL,
						  philosopher_routine, table->philosophers[i]) != 0)
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}

static void	join_threads(t_table *table)
{
	int	i;
	
	i = 0;
	while (i < table->philo_count)
	{
		pthread_join(table->philosophers[i]->thread_id, NULL);
		i ++;
	}
}

int	start_simulation(t_table *table)
{
	pthread_t	monitor_thread;

	if (create_threads(table) == FAILURE)
		return (FAILURE);
	if (pthread_create(&monitor_thread, NULL, death_monitor, table) != 0)
		return (FAILURE);
	pthread_join(monitor_thread, NULL);
	join_threads(table);
	return (SUCCESS);
}

void	cleanup_table(t_table *table)
{
	int	i;
	
	if (!table)
		return;
	if (table->philosophers)
	{
		i = 0;
		while (i < table->philo_count && table->philosophers[i])
		{
			pthread_mutex_destroy(&table->philosophers[i]->meal_lock);
			free(table->philosophers[i]);
			i ++;
		}
		free(table->philosophers);
	}
	if (table->forks)
	{
		i = 0;
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i ++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->death_lock);
	free(table);
}

static int	validate_args(int ac, char **av)
{
	int i;
	int	j;
	
	if (ac < 5 || ac > 6)
	{
		write(2, "Usage: ./philo nb_philos time_die time_eat time_sleep [nb_meals]\n", 66);
		return (FAILURE);
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '\0')
			return (FAILURE);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (FAILURE);
			j ++;
		}
		i ++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_table	*table;
	
	if (validate_args(ac, av) == FAILURE)
		return (1);
	table = init_table(ac, av);
	if (!table)
	{
		write(2, "Error: Failed to initialize\n", 28);
		return (1);
	}
	if (table->philo_count == 1)
	{
		printf("0 1 %s\n", MSG_FORK);
		precise_sleep(table->time_to_die);
		printf("%lld 1 %s\n", table->time_to_die, MSG_DIED);
		cleanup_table(table);
		return (0);
	}
	if (start_simulation(table) == FAILURE)
	{
		cleanup_table(table);
		return (1);
	}
	cleanup_table(table);
	return (0);
}
