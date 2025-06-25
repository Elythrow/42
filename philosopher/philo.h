/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:47:28 by gbazin            #+#    #+#             */
/*   Updated: 2025/06/25 11:55:03 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR		-1
# define OFLOW		-2
# define STDIN		0
# define STDOUT		1
# define STDERR		2
# define GOOD		3
# define ARGVALUE	4
# define EOL		'\0'

typedef struct s_philo
{
	pthread_mutex_t	eating;
	pthread_t		thd_philo;
	pthread_t		myhem;
	int				pid;
	int				nta;
	int				lf;
	int				rf;
	int				is_eating;
	long long		lta;
	struct s_din	*din_table;
}				t_philo;


typedef struct s_din
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	t_philo			**philos;
	long long		st;
	int				death;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				ntpme;
}	t_din;

t_philo			**initialize_philosphers(t_din *din_table);
pthread_mutex_t	*initialize_forks(t_din *din_table);
int				ft_is_number(char *string);
long long		ft_time_in_ms(void);
int				ft_atoi(const char *str);
void			*start_routine(void *data);
void			print_status(t_din *din_table, int pid, char *string);

#endif