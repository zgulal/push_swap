/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_partwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:51:10 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/28 16:07:48 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list *data)
{
	if (data->size_a == 2)
		two_sort(data);
	if (data->size_a == 3)
		three_sort(data);
	if (data->size_a > 3)
	{
		while (data->size_a > 3)
			greater_than_three(data);
		three_sort(data);
		push_a(data);
		if (data->size_b > 0)
			push_a(data);
	}
}

void	greater_than_three(t_list *data)
{
	int	i;

	i = 0;
	data->temp = data->stack_a[0];
	while (i < data->size_a)
	{
		if (data->temp > data->stack_a[i])
		{
			data->temp = data->stack_a[i];
			data->minsize = i;
		}
		i++;
	}
	minpush(data);
}

void	minpush(t_list *data)
{
	int	k;

	k = 0;
	while (k < data->size_a)
	{
		if (data->minsize == 4)
		{
			swap_rra(data);
			data->minsize = 0;
		}
		if (data->stack_a[0] == data->temp)
		{
			push_b(data);
			k = data->size_a;
		}
		else
			swap_ra(data);
		k++;
	}
}
