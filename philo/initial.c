/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:09:54 by akouame           #+#    #+#             */
/*   Updated: 2022/09/12 17:11:29 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*ft_pthread(void *tmp)
{
	t_philosopher	*p;


		// printf("hello mf\n");
	p = (t_philosopher *) tmp;
	if(p->cin % 2)
		usleep (300);
	while (p->news.stop == 0)
	{
		
		// if (p->cin == p->news.nb_p_done)
		// {
		// 	ft_t_fork(&p[p->cin], p->cin);
		// 	ft_t_fork(&p[0], p->cin);
		// }
		// else
		// {
		// 	// printf("cin = %d\n\n", p->cin);
		// }
		
		ft_t_fork(&p[p->cin], p->cin);
		ft_t_fork(&p[p->cin + 1], p->cin);
		ft_eat(p, p->cin);
		pthread_mutex_unlock(&p[p->cin].fork);
		pthread_mutex_unlock(&p[p->cin + 1].fork);
		ft_sleep(p, p->cin);
		ft_print(p, p->cin, "is thinking");
		ft_stop(&p);
		if (p->news.stop == 1)
			break;
	}
	return NULL;
}

void	ft_join(t_philosopher *p)
{
	int i = 0;
	
	while (i < p[i].news.nb_philo)
	{
		pthread_join(*p[i].philo, NULL);
		i++;
	}
}

void	ft_add_philo(t_global *news)
{
	t_philosopher	p[250];
	int				i;

	i = 0;
	while (i < news->nb_philo)
	{
		p[i].philo = malloc (sizeof(pthread_t));
		p[i].chhal_kla = 0;
		p[i].cin = i;
		p[i].last_food = ft_time_rn();
		p[i].news = *news;
		pthread_mutex_init(&p[i].fork, NULL);
		pthread_create(p[i].philo, NULL, ft_pthread, (void *)&p[i]);
		i++;
	}
	ft_join(p);
}

void	ft_add(t_global *news, char **av)
{
	news->nb_philo = ft_atoi(av[1]);
	news->ti_die = ft_atoi(av[2]);
	news->ti_eat = ft_atoi(av[3]);
	news->ti_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		news->must_eat = ft_atoi(av[5]);
	else
		news->must_eat = -1;
	news->start = ft_time_rn();
	news->stop = 0;
	news->nb_p_done = 0;
	pthread_mutex_init(&news->print, NULL);
	ft_add_philo(news);
}