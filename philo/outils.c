/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:01:25 by akouame           #+#    #+#             */
/*   Updated: 2022/09/15 14:05:07 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time_rn(void)
{
	struct timeval	time;
	long		time_rn;

	gettimeofday(&time, NULL);
	time_rn = ((time.tv_sec * 1000000) + time.tv_usec) / 1000;
	return (time_rn);
}

void	ft_print(char *str, t_data *p, int id)
{
	long	time;

	time = ft_time_rn();
	time = time - p->start;
	pthread_mutex_lock(&p->news->print);
	printf ("%ld	%d %s\n", time, id, str);
	pthread_mutex_unlock(&p->news->print);
}