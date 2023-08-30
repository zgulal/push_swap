/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:51:44 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/13 19:51:45 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_list *data)
{
	int	temp;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	swap_sb(t_list *data)
{
	int	temp;

	if (data->size_b > 1)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	swap_ss(t_list *data)
{
	if (data->size_a > 1)
	{
		swap_sa(data);
		swap_sb(data);
		write(1, "ss\n", 3);
	}
}
