/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:01:25 by akouame           #+#    #+#             */
/*   Updated: 2022/09/20 13:42:29 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time_rn(void)
{
	struct timeval	time;
	long long		time_rn;

	gettimeofday(&time, NULL);
	time_rn = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (time_rn);
}

void	ft_print(char *str, t_data *p, int id)
{
	long long	time;

	time = ft_time_rn();
	time = time - p->start;
	pthread_mutex_lock(&p->news->print);
	printf ("%lld	%d %s\n", time, id, str);
	pthread_mutex_unlock(&p->news->print);
}

void	ft_usleep(long long time)
{
	long long	t;

	t = time + ft_time_rn();
	while (ft_time_rn() <= t)
		usleep(50);
}
