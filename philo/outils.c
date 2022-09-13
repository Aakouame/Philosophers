/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:01:25 by akouame           #+#    #+#             */
/*   Updated: 2022/09/12 17:11:08 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time_rn(void)
{
	struct timeval	time;
	long long		time_rn;

	gettimeofday(&time, NULL);
	time_rn = ((time.tv_sec * 1000000) + time.tv_usec) / 1000;
	return (time_rn);
}

void	ft_print(t_philosopher *philo, int cin, char *msg)
{
	long long	t;
	
	pthread_mutex_lock(&philo->news.print);
	t = ft_time_rn();
	t = (t - philo->news.start);
	printf("%lld	%d %s\n", t, cin + 1, msg);
	pthread_mutex_unlock(&philo->news.print);
}

void	ft_stop(t_philosopher **p)
{
	long long	time;
	
	while (1)
	{
		time = ft_time_rn();
		if (time - (*p)->last_food > (*p)->news.ti_die)
		{
			(*p)->news.stop = 1;
			pthread_mutex_lock(&(*p)->news.print);
			printf("%llu	%d is died\n", time, (*p)->cin + 1);
			break;
		}
		if ((*p)->news.must_eat == (*p)->news.nb_p_done)
		{
			(*p)->news.stop = 1;
			pthread_mutex_init(&(*p)->news.check, NULL);
			pthread_mutex_lock(&(*p)->news.check);
			break;
		}
	}
}