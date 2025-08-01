/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:19 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 10:03:31 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_din *din_table)
{
	int	status;

	pthread_mutex_lock(&din_table->death_mutex);
	status = din_table->death;
	pthread_mutex_unlock(&din_table->death_mutex);
	return (status);
}

void	print_status(t_din *din_table, int pid, char *string)
{
	pthread_mutex_lock(&din_table->death_mutex);
	if (!din_table->death)
	{
		pthread_mutex_unlock(&din_table->death_mutex);
		return ;
	}
	pthread_mutex_unlock(&din_table->death_mutex);
	pthread_mutex_lock(&din_table->write);
	printf("%lld %d %s", ft_time_in_ms() - din_table->st, pid + 1, string);
	pthread_mutex_unlock(&din_table->write);
}

void	smart_sleep(t_din *din_table, long long duration)
{
	long long	start;
	long long	elapsed;

	start = ft_time_in_ms();
	while (check_death(din_table))
	{
		elapsed = ft_time_in_ms() - start;
		if (elapsed >= duration)
			break;
		if (duration - elapsed > 10)
			usleep(10000);
		else
			usleep((duration - elapsed) * 1000);
	}
}

static void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->din_table->forks[philo->lf]);
	print_status(philo->din_table, philo->pid, "has taken a fork\n");
	smart_sleep(philo->din_table, philo->din_table->ttd + 1);
	pthread_mutex_unlock(&philo->din_table->forks[philo->lf]);
}

static void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->din_table->forks[philo->lf]);
	print_status(philo->din_table, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->din_table->forks[philo->rf]);
	print_status(philo->din_table, philo->pid, "has taken a fork\n");
}

static void	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->din_table->forks[philo->rf]);
	print_status(philo->din_table, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->din_table->forks[philo->lf]);
	print_status(philo->din_table, philo->pid, "has taken a fork\n");
}

static void	set_eating_state(t_philo *philo, long long eating_start_time)
{
	pthread_mutex_lock(&philo->eating);
	philo->lta = eating_start_time;
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->eating);
}

static void	finish_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	philo->nta++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->din_table->forks[philo->lf]);
	pthread_mutex_unlock(&philo->din_table->forks[philo->rf]);
}

void	eat_routine(t_philo *philo)
{
	long long	eating_start_time;

	if (philo->din_table->nop == 1)
	{
		handle_single_philo(philo);
		return ;
	}
	if (philo->pid % 2 == 0)
		take_forks_even(philo);
	else
		take_forks_odd(philo);
	eating_start_time = ft_time_in_ms();
	set_eating_state(philo, eating_start_time);
	print_status(philo->din_table, philo->pid, "is eating\n");
	smart_sleep(philo->din_table, philo->din_table->tte);
	finish_eating(philo);
}

void	sleep_routine(t_philo *philo)
{
	print_status(philo->din_table, philo->pid, "is sleeping\n");
	smart_sleep(philo->din_table, philo->din_table->tts);
}

void	think_routine(t_philo *philo)
{
	print_status(philo->din_table, philo->pid, "is thinking\n");
	if (philo->din_table->nop % 2 == 1)
		usleep(100);
}

void	*start_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (check_death(philo->din_table))
	{
		eat_routine(philo);
		if (!check_death(philo->din_table))
			break;
		sleep_routine(philo);
		if (!check_death(philo->din_table))
			break;
		think_routine(philo);
	}
	return (NULL);
}
