/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:24:39 by akouame           #+#    #+#             */
/*   Updated: 2022/09/12 17:11:17 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>


typedef struct s_global
{
	int					nb_philo;
	int					ti_die;
	int					ti_sleep;
	long long			start;
	int					ti_eat;
	int					nb_p_done;
	int					must_eat;
	pthread_mutex_t		print;
	pthread_mutex_t			check;
	int					stop;
		
}	t_global;

typedef struct s_philosopher
{
	pthread_t				*philo;
	int						cin;
	pthread_mutex_t			fork;
	int						chhal_kla;
	long long				last_food;
	t_global				news;
	
}	t_philosopher;


//check.c
int	ft_check(char **argv);

//fct_lbft
int	ft_atoi(const char *str);

//initial.c
void	ft_add(t_global *news, char **av);

//outils.c
long long	ft_time_rn(void);
void	ft_print(t_philosopher *philo, int cin, char *msg);
void	ft_stop(t_philosopher **p);
//routine.c
void	ft_t_fork(t_philosopher *first, int cin);
void	ft_eat(t_philosopher *philo, int cin);
void	ft_sleep(t_philosopher *philo, int cin);

#endif