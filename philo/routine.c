/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:09:20 by akouame           #+#    #+#             */
/*   Updated: 2022/09/11 20:16:44 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_t_fork(t_philosopher *first, int cin)
{
	pthread_mutex_lock(&first->fork);
	ft_print(first, cin, "take a fork");
	// pthread_mutex_unlock(&first->fork);
}

void	ft_eat(t_philosopher *philo, int cin)
{
	philo->last_food = ft_time_rn();
	philo->chhal_kla++;
	ft_print(philo, cin, "is eating");
	if (philo->chhal_kla == philo->news.must_eat)
		philo->news.nb_p_done++;
	usleep(philo->news.ti_eat * 1000);
}

void	ft_sleep(t_philosopher *philo, int cin)
{
	ft_print(philo, cin, "is sleeping");
	usleep(philo->news.ti_sleep * 1000);
}