/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:24:39 by akouame           #+#    #+#             */
/*   Updated: 2022/09/16 15:37:14 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	pthread_mutex_t	print;
	int				stop;
	int				nb_philo;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
	int				nb_phi_must;

}	t_info;

typedef struct s_data
{
	pthread_t		thread_philo;
	int				id;
	int				nb_food;
	long			last_eat;
	t_info			*news;
	struct s_data	*next;
	long			start;

}	t_data;

int		ft_check(char **argv);
int		ft_atoi(const char *str);
void	ft_pub_news(t_info *new, char **av, t_data *p);
long	ft_time_rn(void);
void	ft_print(char *str, t_data *p, int id);
void	ft_usleep(long time);
void	ft_eat(t_data *p, int id);
void	ft_sleep(t_data *p, int id);
void	ft_think(t_data *p, int id);
void	ft_check_stop(t_data *p);

#endif