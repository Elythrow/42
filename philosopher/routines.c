/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:19 by gbazin            #+#    #+#             */
/*   Updated: 2025/06/25 11:55:15 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Affiche le statut d'un philosophe dans un mutex
// pour éviter que l'affichage soit confondu entre plusieurs philosophes

void	print_status(t_din *din_table, int pid, char *string)
{
	pthread_mutex_lock(&din_table->write);
	printf("%lld %d %s", ft_time_in_ms() - din_table->st, pid + 1, string);
	if (string[0] != 'd')
		pthread_mutex_unlock(&din_table->write);
}

// Le philosophe prend ses deux fourchettes et commence la routine manger
// pendant une certaine durée (tte)

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->din_table->forks[philo->lf]);
	print_status(philo->din_table, philo->pid, "taken left fork\n");
	pthread_mutex_lock(&philo->din_table->forks[philo->rf]);
	print_status(philo->din_table, philo->pid, "taken right fork\n");
	pthread_mutex_lock(&philo->eating);
	print_status(philo->din_table, philo->pid, "is eating\n");
	philo->lta = ft_time_in_ms();
	philo->is_eating = 1;
	usleep(philo->din_table->tte * 1000 - 16000);
	while (ft_time_in_ms() - philo->lta < philo->din_table->tte)
		continue ;
	philo->nta++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->din_table->forks[philo->lf]);
	pthread_mutex_unlock(&philo->din_table->forks[philo->rf]);
	return ;
}

//Routine dormir 

void	sleep_routine(t_philo *philo)
{
	long long	time;

	print_status(philo->din_table, philo->pid, "is sleeping\n");
	time = ft_time_in_ms();
	usleep(philo->din_table->tts * 1000 - 16000);
	while (ft_time_in_ms() - time < philo->din_table->tts)
		continue ;
	return ;
}

//Routine réfléchir

void	think_routine(t_philo *philo)
{
	print_status(philo->din_table, philo->pid, "is thinking\n");
	return ;
}

// Début de routine via une boucle infinie incluant toutes les routines que tous les philosophes doivent effectuer

void	*start_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->din_table->death)
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
		usleep(100);
	}
	return (NULL);
}
