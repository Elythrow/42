/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:21:48 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 11:36:56 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Check if simulation should continue */
bool	is_simulation_running(t_table *table)
{
	bool	running;
	
	pthread_mutex_lock(&table->death_lock);
	running = !table->simulation_stop;
	pthread_mutex_unlock(&table->death_lock);
	return (running);
}

/* Simplified fork taking - avoid deadlock with consistent ordering */
void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, MSG_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, MSG_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, MSG_FORK);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, MSG_FORK);
	}
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

/* Eating with proper synchronization */
void	eat_action(t_philosopher *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_ms();
	philo->is_eating = true;
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, MSG_EAT);
	precise_sleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->meals_eaten ++;
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->meal_lock);
	release_forks(philo);
}

void	sleep_action(t_philosopher *philo)
{
	print_status(philo, MSG_SLEEP);
	precise_sleep(philo->table->time_to_sleep);
}

void	think_action(t_philosopher *philo)
{
	long think_time;
	
	print_status(philo, MSG_THINK);
	if (philo->table->philo_count % 2 == 1)
	{
		think_time = (philo->table->time_to_eat * 2 - philo->table->time_to_sleep) / 2;
		if (think_time > 0)
			precise_sleep(think_time);
	}
}

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo;
	
	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		precise_sleep(philo->table->time_to_eat / 2);
	while (is_simulation_running(philo->table))
	{
		eat_action(philo);
		if (philo->table->required_meals != -1 
			&& philo->meals_eaten >= philo->table->required_meals)
			break ;
		if (!is_simulation_running(philo->table))
			break ;
		sleep_action(philo);
		if (!is_simulation_running(philo->table))
			break ;
		think_action(philo);
	}
	return (NULL);
}
