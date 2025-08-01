/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:21:24 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 12:47:35 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	has_philosopher_died(t_philosopher *philo)
{
	long long	current_time;
	long long	time_since_meal;
	bool		died;
	
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->is_eating)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (false);
	}
	current_time = get_time_ms();
	time_since_meal = current_time - philo->last_meal_time;
	died = (time_since_meal > philo->table->time_to_die);
	pthread_mutex_unlock(&philo->meal_lock);
	return (died);
}

static bool	all_philosophers_satisfied(t_table *table)
{
	int	i;
	
	if (table->required_meals == -1)
		return (false);
	i = 0;
	while (i < table->philo_count)
	{
		if (table->philosophers[i]->meals_eaten < table->required_meals)
			return (false);
		i ++;
	}
	return (true);
}

static void	announce_death(t_table *table, int philo_id)
{
	pthread_mutex_lock(&table->death_lock);
	table->simulation_stop = true;
	pthread_mutex_unlock(&table->death_lock);
	pthread_mutex_lock(&table->print_lock);
	printf("%lld %d %s\n",
		get_time_ms() - table->start_time,
		philo_id,
		MSG_DIED);
	pthread_mutex_unlock(&table->print_lock);
}

static bool	check_deaths(t_table *table)
{
	int			i;
	t_philosopher	*philo;

	i = 0;
	while (i < table->philo_count)
	{
		philo = table->philosophers[i];
		if (has_philosopher_died(philo))
		{
			announce_death(table, philo->id);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	check_all_satisfied(t_table *table)
{
	bool	all_satisfied;

	all_satisfied = all_philosophers_satisfied(table);
	if (all_satisfied)
	{
		pthread_mutex_lock(&table->death_lock);
		table->simulation_stop = true;
		pthread_mutex_unlock(&table->death_lock);
	}
	return (all_satisfied);
}

void	*death_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	precise_sleep(10);
	while (is_simulation_running(table))
	{
		if (check_deaths(table))
			return (NULL);
		if (check_all_satisfied(table))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

