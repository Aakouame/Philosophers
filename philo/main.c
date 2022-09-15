/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:26:59 by akouame           #+#    #+#             */
/*   Updated: 2022/09/14 21:50:05 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
	t_info	new;
	t_data	p;

	// new.stop = 0;    ex
	if (ac == 5 || ac == 6)
	{
		// new = NULL;
		// p = NULL;
		if (ft_check(av))
		{
			printf("Error: Check ur inputs !\n");
			return (-1);
		}

		//new = malloc(sizeof(t_info *));
		ft_pub_news(&new, av, &p);
		
	}
	else
	{
		printf("Error: Check how many arg u write\n");
		return (-1);
	}
		
	
	return (0);
}