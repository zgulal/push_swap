/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:51:53 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/13 19:52:03 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ra(t_list *data)
{
	int	tmp;
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		i = 0;
		while (i < data->size_a - 1)
		{
			tmp = data->stack_a[i];
			data->stack_a[i] = data->stack_a[i + 1];
			data->stack_a[i + 1] = tmp;
			i++;
		}
		data->stack_a[data->size_a - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	swap_rb(t_list *data)
{
	int	tmp;
	int	temp;
	int	i;

	if (data->size_b > 1)
	{
		temp = data->stack_b[0];
		i = 0;
		while (i < data->size_b - 1)
		{
			tmp = data->stack_b[i];
			data->stack_b[i] = data->stack_b[i + 1];
			data->stack_b[i + 1] = tmp;
			i++;
		}
		data->stack_b[data->size_b - 1] = temp;
		write(1, "rb\n", 3);
	}
}

void	swap_rr(t_list *data)
{
	if (data->size_a > 1)
	{
		swap_ra(data);
		swap_rb(data);
		write(1, "rr\n", 3);
	}
}
