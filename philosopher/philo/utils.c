/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:48:53 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 10:03:24 by gbazin           ###   ########.fr       */
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
		str ++;
	}
	else if (*str == '+')
		str ++;
	while (*(str + j) >= 48 && *(str + j) <= 57)
		t_p = t_p * 10 + (unsigned long long int)(*(str + j++) - '0');
	return (ft_check(t_p, tt));
}

int	ft_is_number(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '-' || string[0] == '+')
		i++;
	if (string[i] == EOL)
		return (ERROR);
	while (string[i] != EOL)
	{
		if (string[i] < '0' || string[i] > '9')
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

static void	cleanup_philosophers(t_philo **philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (philos[i])
		{
			pthread_mutex_destroy(&philos[i]->eating);
			free(philos[i]);
		}
		i++;
	}
	free(philos);
}

static void	init_philosopher_fields(t_philo *philo, t_din *din_table, int i)
{
	philo->din_table = din_table;
	philo->pid = i;
	philo->is_eating = 0;
	philo->nta = 0;
	philo->lf = i;
	philo->rf = (i + 1) % din_table->nop;
	philo->lta = 0;
}

static t_philo	*create_single_philosopher(t_din *din_table, int i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (philo == NULL)
		return (NULL);
	if (pthread_mutex_init(&philo->eating, 0) != 0)
	{
		free(philo);
		return (NULL);
	}
	init_philosopher_fields(philo, din_table, i);
	return (philo);
}

t_philo	**initialize_philosphers(t_din *din_table)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * din_table->nop);
	if (philos == NULL)
		return (NULL);
	while (i < din_table->nop)
	{
		philos[i] = create_single_philosopher(din_table, i);
		if (philos[i] == NULL)
		{
			cleanup_philosophers(philos, i);
			return (NULL);
		}
		i++;
	}
	return (philos);
}