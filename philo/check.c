/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:22:30 by akouame           #+#    #+#             */
/*   Updated: 2022/09/18 14:01:47 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_dig(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}

int	ft_check(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n <= 0 || ft_check_dig(argv[i]) || n > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}
