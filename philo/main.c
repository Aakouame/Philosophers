/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:26:59 by akouame           #+#    #+#             */
/*   Updated: 2022/09/18 23:26:40 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_info *new)
{
	int	i;

	i = 0;
	while (i < new->nb_philo)
	{
		pthread_mutex_destroy(&new->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&new->print);
}

int	main(int ac, char **av)
{
	t_info	new;

	if (ac == 5 || ac == 6)
	{
		if (ft_check(av))
		{
			printf("Error: Check ur inputs !\n");
			return (1);
		}
		if (ft_pub_news(&new, av) != 0)
		{
			printf ("Error: (malloc || mutex)\n");
			return (1);
		}
		ft_destroy(&new);
	}
	else
	{
		printf("Error: Check how many arg u write\n");
		return (1);
	}
	return (0);
}
