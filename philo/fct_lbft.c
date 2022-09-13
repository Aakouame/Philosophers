/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lbft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:13:31 by akouame           #+#    #+#             */
/*   Updated: 2022/08/29 09:30:58 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\f' || c == '\v' || c == '\r');
}

static long int	ft_result(const char	*str, int i)
{
	long int	r;
	int			j;

	r = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
		j++;
	}
	if (j > 10)
		return (0);
	if (j == 10 && (str[i - j] > '3'))
		return (0);
	return (r);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	int			k;

	i = 0;
	s = 1;
	k = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
		k++;
	}
	if (k > 1)
		return (0);
	return (ft_result(str, i) * s);
}
