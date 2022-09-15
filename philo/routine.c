/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:09:20 by akouame           #+#    #+#             */
/*   Updated: 2022/09/15 14:05:53 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_data *p, int id)
{
	pthread_mutex_lock(&p->news->forks[id]);
	ft_print("take a fork", p, id + 1);
	if (id != p->news->nb_philo - 1)
	{
		pthread_mutex_lock(&p->news->forks[id + 1]);
		ft_print("take a fork", p, id + 1);
	}
	else if (id == p->news->nb_philo - 1)
	{
		pthread_mutex_lock(&p->news->forks[0]);
		ft_print("take a fork", p, id + 1);
	}
	ft_print("is eating", p, id + 1);
	p->nb_food++;
	if (p->nb_food == p->news->must_eat)
		p->news->nb_phi_must++;
	p->last_eat = ft_time_rn();
	usleep(p->news->time_eat);
	pthread_mutex_unlock(&p->news->forks[id]);
	if (id != p->news->nb_philo - 1)
		pthread_mutex_unlock(&p->news->forks[id + 1]);
	else if (id == p->news->nb_philo - 1)
		pthread_mutex_unlock(&p->news->forks[0]);

}

void	ft_sleep(t_data *p, int id)
{
	ft_print("is sleeping", p, id + 1);
	usleep(p->news->time_sleep);
}

void	ft_think(t_data *p, int id)
{
	ft_print("is thinking", p, id + 1);
}

int	ft_check_stop(t_data *p)
{
	int		i;
	long	t;
	
	i = 0;
	while (1)
	{
		if ((ft_time_rn() - p->last_eat) > p->news->time_die)
		{
			pthread_mutex_lock(&p->news->print);
			t = ft_time_rn() - p->start;
			printf("%ld	%d died\n", t, p->id + 1);
			p->news->stop = 1;
			// pthread_mutex_destroy(&p->news->print);
			// pthread_mutex_unlock(&p->news->print);
			// pthread_mutex_destroy(p->news->forks);
			break ;
		}
		if (p->news->must_eat == p->news->nb_phi_must)
		{
			pthread_mutex_lock(&p->news->print);
			p->news->stop = 1;
			// pthread_mutex_unlock(&p->news->print);
			// pthread_mutex_destroy(p->news->forks);
			break ;
		}
	}
	return (p->news->stop);
}