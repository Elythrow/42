/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:45:43 by gbazin            #+#    #+#             */
/*   Updated: 2025/07/29 10:05:29 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*initialize_forks(t_din *din_table)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	if (din_table->nop == OFLOW || din_table->ttd == OFLOW
		|| din_table->tte == OFLOW || din_table->tts == OFLOW
		|| din_table->ntpme == OFLOW)
	{
		write(2, "Error: Invalid Argument\n", 23);
		return (NULL);
	}
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * din_table->nop);
	if (forks == NULL)
		return (NULL);
	while (i < din_table->nop)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL);
		i ++;
	}
	return (forks);
}
