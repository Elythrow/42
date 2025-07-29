/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:59 by gbazin            #+#    #+#             */
/*   Updated: 2025/07/29 10:29:44 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_validity(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac - 1 < 4 || ac - 1 > 6)
		return (ERROR);
	while (i < ac)
	{
		if (av[i][0] == '-' || ft_is_number(av[i]) != GOOD)
			return (ERROR);
		i ++;
	}
	return (GOOD);
}

t_din	*fill_table(int ac, char **av)
{
	t_din	*din_table;
	int		counter;

	counter = 1;
	din_table = (t_din *) malloc(sizeof(t_din) * 1);
	if (din_table == NULL)
		return (NULL);
	din_table->nop = ft_atoi(av[counter++]);
	din_table->ttd = ft_atoi(av[counter++]);
	din_table->tte = ft_atoi(av[counter++]);
	din_table->tts = ft_atoi(av[counter++]);
	din_table->ntpme = -1;
	din_table->death = 1;
	if (ac - 1 == 5)
		din_table->ntpme = ft_atoi(av[counter]);
	din_table->forks = initialize_forks(din_table);
	if (din_table->forks == NULL)
		return (NULL);
	din_table->philos = initialize_philosphers(din_table);
	if (din_table->philos == NULL || din_table->nop == 0)
		return (NULL);
	if (pthread_mutex_init(&din_table->write, 0) != 0)
		return (NULL);
	if (pthread_mutex_init(&din_table->death_mutex, 0) != 0)
		return (NULL);
	return (din_table);
}

void	*monitor_philosophers(void *data)
{
	t_din	*din_table;
	int		i;
	int		all_ate_enough;
	long long	current_time;

	din_table = (t_din *)data;
	while (din_table->death)
	{
		i = 0;
		all_ate_enough = 1;
		current_time = ft_time_in_ms();
		while (i < din_table->nop)
		{
			pthread_mutex_lock(&din_table->philos[i]->eating);
			if (!din_table->philos[i]->is_eating
				&& current_time - din_table->philos[i]->lta >= din_table->ttd)
			{
				pthread_mutex_lock(&din_table->death_mutex);
				din_table->death = 0;
				pthread_mutex_unlock(&din_table->death_mutex);
				pthread_mutex_lock(&din_table->write);
				printf("%lld %d died\n", current_time - din_table->st, 
					din_table->philos[i]->pid + 1);
				pthread_mutex_unlock(&din_table->write);
				pthread_mutex_unlock(&din_table->philos[i]->eating);
				return (NULL);
			}
			if (din_table->ntpme != -1 
				&& din_table->philos[i]->nta < din_table->ntpme)
				all_ate_enough = 0;
			pthread_mutex_unlock(&din_table->philos[i]->eating);
			i ++;
		}
		if (din_table->ntpme != -1 && all_ate_enough)
		{
			pthread_mutex_lock(&din_table->death_mutex);
			din_table->death = 0;
			pthread_mutex_unlock(&din_table->death_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

//Initialisation des threads
int	start_threads(t_din *din_table)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	din_table->st = ft_time_in_ms();
	while (i < din_table->nop)
	{
		din_table->philos[i]->lta = ft_time_in_ms();
		if (pthread_create(&din_table->philos[i]->thd_philo, NULL,
			&start_routine, (void *)din_table->philos[i]) != 0)
			return (ERROR);
		i ++;
		usleep(100);
	}
	if (pthread_create(&monitor, NULL, &monitor_philosophers, 
		(void *)din_table) != 0)
		return (ERROR);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < din_table->nop)
	{
		pthread_join(din_table->philos[i]->thd_philo, NULL);
		i ++;
	}
	return (GOOD);
}

void	cleanup_table(t_din *din_table)
{
	int	i;

	if (din_table == NULL)
		return ;
	i = 0;
	while (i < din_table->nop && din_table->philos && din_table->philos[i])
	{
		pthread_mutex_destroy(&din_table->philos[i]->eating);
		free(din_table->philos[i]);
		i ++;
	}
	i = 0;
	while (i < din_table->nop && din_table->forks)
	{
		pthread_mutex_destroy(&din_table->forks[i]);
		i ++;
	}
	pthread_mutex_destroy(&din_table->write);
	pthread_mutex_destroy(&din_table->death_mutex);
	if (din_table->philos)
		free(din_table->philos);
	if (din_table->forks)
		free(din_table->forks);
	free(din_table);
}

int	main(int ac, char **av)
{
	t_din	*din_table;

	din_table = NULL;
	if (check_arg_validity(ac, av) != GOOD)
	{
		write(2, "Error: Invalid Argument\n", 24);
		return (ERROR);
	}
	din_table = fill_table(ac, av);
	if (din_table == NULL)
		return (ERROR);
	if (start_threads(din_table) != GOOD)
	{
		cleanup_table(din_table);
		return (ERROR);
	}
	cleanup_table(din_table);
	return (GOOD);
}
