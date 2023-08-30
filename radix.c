/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:50:47 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/28 16:09:17 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bit(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->size_a - 1;
	if (j == 0)
	{
		return (1);
	}
	while (j)
	{
		j >>= 1;
		i++;
	}
	return (i);
}

int	find_index(int *arr, int value)
{
	int	i;

	i = 0;
	while (arr[i] != value)
		i++;
	return (i);
}

void	radixidx(t_list *data)
{
	int	i;

	i = 0;
	while (data->size_a != i)
	{
		data->stack_a[i] = find_index(data->tmp_a, data->stack_a[i]);
		i++;
	}
}

void	radix(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	radixidx(data);
	while (i < bit(data))
	{
		j = 0;
		while (j < data->size_tmp)
		{
			if ((data->stack_a[0] >> i) & 1)
				swap_ra(data);
			else
				push_b(data);
			j++;
		}
		while (data->size_b)
			push_a(data);
		i++;
	}
}
