/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:20:05 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 12:11:40 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	precise_sleep(long duration_ms)
{
	long long	start_time;
	long long	current_time;
	long		remaining;
	
	start_time = get_time_ms();
	while (1)
	{
		current_time = get_time_ms();
		if (current_time - start_time >= duration_ms)
			break ;
		remaining = duration_ms - (current_time - start_time);
		if (remaining > 10)
			usleep(5000);
		else if (remaining > 1)
			usleep(500);
		else
			usleep(100);
	}
}

void	print_status(t_philosopher *philo, char *action)
{
	if (philo->table->simulation_stop)
		return ;
	pthread_mutex_lock(&philo->table->death_lock);
	if (!philo->table->simulation_stop)
	{
		pthread_mutex_unlock(&philo->table->death_lock);
		
		pthread_mutex_lock(&philo->table->print_lock);
		printf("%lld %d %s\n", 
			get_time_ms() - philo->table->start_time,
			philo->id,
			action);
		pthread_mutex_unlock(&philo->table->print_lock);
	}
	else
		pthread_mutex_unlock(&philo->table->death_lock);
}
