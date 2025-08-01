/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/08/01 11:31:00 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# define SUCCESS    0
# define FAILURE    -1

# define MSG_FORK   "has taken a fork"
# define MSG_EAT    "is eating"
# define MSG_SLEEP  "is sleeping"
# define MSG_THINK  "is thinking"
# define MSG_DIED   "died"

typedef struct s_philosopher
{
	pthread_t			thread_id;
	int					id;
	int					meals_eaten;
	long long			last_meal_time;
	bool				is_eating;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_table		*table;
} t_philosopher;

typedef struct s_table
{
	t_philosopher		**philosophers;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		death_lock;
	long long			start_time;
	int					philo_count;
	long long			time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					required_meals;
	bool				simulation_stop;
} t_table;

t_table			*init_table(int ac, char **av);
int				init_philosophers(t_table *table);
int				init_forks(t_table *table);
int				start_simulation(t_table *table);
void			*philosopher_routine(void *arg);
void			*death_monitor(void *arg);
void			take_forks(t_philosopher *philo);
void			release_forks(t_philosopher *philo);
void			eat_action(t_philosopher *philo);
void			sleep_action(t_philosopher *philo);
void			think_action(t_philosopher *philo);
long long		get_time_ms(void);
void			precise_sleep(long duration_ms);
void			print_status(t_philosopher *philo, char *action);
bool			is_simulation_running(t_table *table);
bool			has_philosopher_died(t_philosopher *philo);
int				ft_atoi(const char *str);
void			cleanup_table(t_table *table);

#endif