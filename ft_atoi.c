/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:50 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/28 14:40:42 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer_overflow(long long num, int sign)
{
	if (((num * sign) > 2147483647) || ((num * sign) < -2147483648))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_check(char *str)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		ft_error();
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
		ft_error();
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_error();
		}
		i++;
	}
}

long	ft_atoi(char *str)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	ft_check(str);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		is_integer_overflow(num, sign);
		i++;
	}
	return (num * sign);
}
