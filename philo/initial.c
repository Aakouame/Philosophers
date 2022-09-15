/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:09:54 by akouame           #+#    #+#             */
/*   Updated: 2022/09/15 17:43:37 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_pthread(void *p)
{
	t_data	*philo;
	
	philo = (t_data *)p;
	// printf("%d\n", philo->id);
	// if (philo->id % 2)
	// 	usleep(300);
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
	// t_data	*philo;
	
	i = 0;
	// philo = malloc (sizeof (t_data *));
	while (i < new->nb_philo)
	{
	// printf ("nb_philo = %d\n", new->nb_philo);
		p[i].id = i;
		p[i].last_eat = ft_time_rn();
		p[i].nb_food = 0;
		p[i].news = new;
		p[i].start = ft_time_rn();
		if (i == new->nb_philo - 1)
			p[i].next = &p[0];
		else
			p[i].next = &p[i + 1];
		// p[i].thread_philo = malloc(sizeof(pthread_t));
		// printf("lll");
		pthread_create(&p->thread_philo, NULL, ft_pthread, &p[i]);
		i++;
		// printf("mal moke\n");
		usleep(50);
	}
	
}

void	ft_pub_news(t_info *new, char **av, t_data *p)
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
	while (i < new->nb_philo)
	{
		// printf("hello1\n");
		pthread_mutex_init(&new->forks[i], NULL);
		i++;
	}
	p = malloc (sizeof(t_data) * new->nb_philo);
	ft_add(p, new);
	while (1)
	{		
		if ((ft_time_rn() - p->last_eat) >= p->news->time_die)
		{
			pthread_mutex_lock(&p->news->print);
			printf("%ld	%d died\n", ft_time_rn() - p->start, p->id + 1);
			return ;
			// pthread_mutex_unlock(&p->news->print);
			// pthread_mutex_destroy(&p->news->print);
			// pthread_mutex_unlock(&p->news->print);
			// pthread_mutex_destroy(p->news->forks);
		}

		if (p->news->nb_philo == p->news->nb_phi_must)
		{
			pthread_mutex_lock(&p->news->print);
			p->news->stop = 1;
			// pthread_mutex_unlock(&p->news->print);
			// pthread_mutex_destroy(p->news->forks);
			return ;
		}
		p = p->next;
	}
	// pthread_mutex_unlock(&p->news->print);
	// pthread_detach(p->thread_philo);
	// while (i < new->nb_philo)
	// {
	// 	pthread_join(p[i].thread_philo, NULL);
	// 	i++;
	// }
	
}