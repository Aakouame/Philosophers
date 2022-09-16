/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:09:54 by akouame           #+#    #+#             */
/*   Updated: 2022/09/16 15:34:38 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_pthread(void *p)
{
	t_data	*philo;

	philo = (t_data *)p;
	while (philo->news->stop == 0)
	{
		ft_eat(philo, philo->id);
		ft_sleep(philo, philo->id);
		ft_think(philo, philo->id);
	}
	return (NULL);
}

void	ft_add(t_data *p, t_info *new)
{
	int	i;

	i = 0;
	while (i < new->nb_philo)
	{
		p[i].id = i;
		p[i].last_eat = ft_time_rn();
		p[i].nb_food = 0;
		p[i].news = new;
		p[i].start = ft_time_rn();
		if (i == new->nb_philo - 1)
			p[i].next = &p[0];
		else
			p[i].next = &p[i + 1];
		pthread_create(&p->thread_philo, NULL, ft_pthread, &p[i]);
		i++;
		usleep(50);
	}
}

void	ft_check_stop(t_data *p)
{
	while (1)
	{		
		if (p->news->nb_philo == p->news->nb_phi_must)
		{
			pthread_mutex_lock(&p->news->print);
			p->news->stop = 1;
			return ;
		}
		else if ((ft_time_rn() - p->last_eat) >= p->news->time_die)
		{
			pthread_mutex_lock(&p->news->print);
			printf("%ld	%d died\n", ft_time_rn() - p->start, p->id + 1);
			return ;
		}
		p = p->next;
	}
}

void	ft_add_news(t_info *new, char **av)
{
	int		i;

	new->nb_philo = ft_atoi(av[1]);
	new->time_die = ft_atoi(av[2]);
	new->time_eat = ft_atoi(av[3]);
	new->time_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		new->must_eat = ft_atoi(av[5]);
	else
		new->must_eat = -1;
	new->stop = 0;
	new->nb_phi_must = 0;
	pthread_mutex_init(&new->print, NULL);
	i = 0;
	new->forks = malloc(sizeof(pthread_mutex_t) * new->nb_philo);
	if (!new->forks)
		return ;
	while (i < new->nb_philo)
	{
		pthread_mutex_init(&new->forks[i], NULL);
		i++;
	}
}

void	ft_pub_news(t_info *new, char **av, t_data *p)
{
	ft_add_news(new, av);
	p = malloc (sizeof(t_data) * new->nb_philo);
	if (!p)
		return ;
	ft_add(p, new);
	ft_check_stop(p);
}
