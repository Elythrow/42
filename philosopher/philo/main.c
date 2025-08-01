/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:59 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 10:03:33 by gbazin           ###   ########.fr       */
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
		i++;
	}
	return (GOOD);
}

static int	init_mutexes(t_din *din_table)
{
	if (pthread_mutex_init(&din_table->write, 0) != 0)
		return (ERROR);
	if (pthread_mutex_init(&din_table->death_mutex, 0) != 0)
		return (ERROR);
	return (GOOD);
}

static int	fill_table_values(t_din *din_table, int ac, char **av)
{
	int	counter;

	counter = 1;
	din_table->nop = ft_atoi(av[counter++]);
	din_table->ttd = ft_atoi(av[counter++]);
	din_table->tte = ft_atoi(av[counter++]);
	din_table->tts = ft_atoi(av[counter++]);
	din_table->ntpme = -1;
	din_table->death = 1;
	if (ac - 1 == 5)
		din_table->ntpme = ft_atoi(av[counter]);
	return (GOOD);
}

t_din	*fill_table(int ac, char **av)
{
	t_din	*din_table;

	din_table = (t_din *)malloc(sizeof(t_din) * 1);
	if (din_table == NULL)
		return (NULL);
	fill_table_values(din_table, ac, av);
	din_table->forks = initialize_forks(din_table);
	if (din_table->forks == NULL)
		return (NULL);
	din_table->philos = initialize_philosphers(din_table);
	if (din_table->philos == NULL || din_table->nop == 0)
		return (NULL);
	if (init_mutexes(din_table) != GOOD)
		return (NULL);
	return (din_table);
}

static int	check_philosopher_death(t_din *din_table, int i)
{
	long long	current_time;
	long long	time_since_meal;

	current_time = ft_time_in_ms();
	time_since_meal = current_time - din_table->philos[i]->lta;
	if (time_since_meal > din_table->ttd)
	{
		pthread_mutex_lock(&din_table->death_mutex);
		din_table->death = 0;
		pthread_mutex_unlock(&din_table->death_mutex);
		pthread_mutex_lock(&din_table->write);
		printf("%lld %d died\n", current_time - din_table->st,
			din_table->philos[i]->pid + 1);
		pthread_mutex_unlock(&din_table->write);
		return (1);
	}
	return (0);
}

static int	monitor_single_philo(t_din *din_table, int i)
{
	int	death_occurred;

	pthread_mutex_lock(&din_table->philos[i]->eating);
	death_occurred = 0;
	if (!din_table->philos[i]->is_eating)
	{
		death_occurred = check_philosopher_death(din_table, i);
		if (death_occurred)
		{
			pthread_mutex_unlock(&din_table->philos[i]->eating);
			return (1);
		}
	}
	pthread_mutex_unlock(&din_table->philos[i]->eating);
	return (0);
}

static int	check_all_ate_enough(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop)
	{
		if (din_table->ntpme != -1
			&& din_table->philos[i]->nta < din_table->ntpme)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_philosophers(void *data)
{
	t_din	*din_table;
	int		i;

	din_table = (t_din *)data;
	usleep(10000);
	while (din_table->death)
	{
		i = 0;
		while (i < din_table->nop)
		{
			if (monitor_single_philo(din_table, i))
				return (NULL);
			i++;
		}
		if (din_table->ntpme != -1 && check_all_ate_enough(din_table))
		{
			pthread_mutex_lock(&din_table->death_mutex);
			din_table->death = 0;
			pthread_mutex_unlock(&din_table->death_mutex);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static void	initialize_philosopher_times(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop)
	{
		din_table->philos[i]->lta = din_table->st;
		i++;
	}
}

static int	create_philosopher_threads(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop)
	{
		if (pthread_create(&din_table->philos[i]->thd_philo, NULL,
				&start_routine, (void *)din_table->philos[i]) != 0)
			return (ERROR);
		i++;
	}
	return (GOOD);
}

static void	join_philosopher_threads(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop)
	{
		pthread_join(din_table->philos[i]->thd_philo, NULL);
		i++;
	}
}

int	start_threads(t_din *din_table)
{
	pthread_t	monitor;

	din_table->st = ft_time_in_ms();
	initialize_philosopher_times(din_table);
	if (create_philosopher_threads(din_table) != GOOD)
		return (ERROR);
	if (pthread_create(&monitor, NULL, &monitor_philosophers,
			(void *)din_table) != 0)
		return (ERROR);
	pthread_join(monitor, NULL);
	join_philosopher_threads(din_table);
	return (GOOD);
}

static void	cleanup_philosophers(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop && din_table->philos && din_table->philos[i])
	{
		pthread_mutex_destroy(&din_table->philos[i]->eating);
		free(din_table->philos[i]);
		i++;
	}
}

static void	cleanup_forks(t_din *din_table)
{
	int	i;

	i = 0;
	while (i < din_table->nop && din_table->forks)
	{
		pthread_mutex_destroy(&din_table->forks[i]);
		i++;
	}
}

void	cleanup_table(t_din *din_table)
{
	if (din_table == NULL)
		return ;
	cleanup_philosophers(din_table);
	cleanup_forks(din_table);
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
