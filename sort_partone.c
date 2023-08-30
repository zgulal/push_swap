/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_partone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:51:00 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/13 19:51:01 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_list *data)
{
	if (data->stack_a[0] > data->stack_a[1])
		swap_sa(data);
}

void	three_sort(t_list *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		swap_sa(data);
		swap_rra(data);
	}
	else if (data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[1])
		swap_ra(data);
	else if (data->stack_a[1] > data->stack_a[0]
		&& data->stack_a[0] > data->stack_a[2])
	{
		swap_rra(data);
	}
	else if (data->stack_a[1] > data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
	{
		swap_sa(data);
		swap_ra(data);
	}
	else if (data->stack_a[2] > data->stack_a[0]
		&& data->stack_a[0] > data->stack_a[1])
	{
		swap_sa(data);
	}
}
