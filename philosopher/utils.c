/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:53 by gbazin            #+#    #+#             */
/*   Updated: 2025/06/25 11:55:19 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(unsigned long pt, int s)
{
	if (pt > 9223372036854775807 && s == -1)
		return (0);
	else if (pt > 2147483647)
		return (OFLOW);
	return (pt * s);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	j;
	unsigned long long int	t_p;
	int						tt;

	tt = 1;
	j = 0;
	t_p = 0;
	while (*str >= 8 && *str <= 32)
	{
		if (*str == 27)
			return (0);
		str++;
	}
	if (*str == '-')
	{
		tt = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		t_p = t_p * 10 + (unsigned long long int)(*(str + j++) - '0');
	return (ft_check(t_p, tt));
}

int	ft_is_number(char *string)
{
	int	i;

	i = 0;
	while (string[i] != EOL)
	{
		if (string[i] <= '0' || string[i] >= '9')
			return (ERROR);
		i++;
	}
	return (GOOD);
}

long long	ft_time_in_ms(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

//initialisation de la structure d'un philosophe

t_philo	**initialize_philosphers(t_din *din_table)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * din_table->nop + 1);
	if (philos == NULL)
		return (NULL);
	while (i < din_table->nop)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (philos[i] == NULL)
			return (NULL);
		if (pthread_mutex_init(&philos[i]->eating, 0) != 0)
			return (NULL);
		philos[i]->din_table = din_table;
		philos[i]->pid = i;
		philos[i]->is_eating = 0;
		philos[i]->nta = 0;
		philos[i]->lf = i;
		philos[i]->rf = (i + 1) % philos[i]->din_table->nop;
		i++;
	}
	return (philos);
}
