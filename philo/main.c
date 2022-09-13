/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:26:59 by akouame           #+#    #+#             */
/*   Updated: 2022/09/12 13:53:58 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_global		*news;
	int				i;
	
	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_check(argv))
		{
			printf("Error : Check ur input\n");
			return (0);
		}
		news = malloc(sizeof (t_global));
		ft_add(news, argv);
	}
	else
		printf("Error: Check how many args you are writing\n");
	// while (1);
}
