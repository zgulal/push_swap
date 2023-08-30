/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:50:01 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/28 16:08:41 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	control_size(t_list *data, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			error_message();
		j = 0;
		data->split = ft_split(av[i], ' ');
		while (data->split[j])
		{
			size++;
			j++;
		}
		free_split(data->split);
		i++;
	}
	data->size_a = size;
	data->size_b = 0;
	data->size_tmp = size;
}

void	fill_stack_a(t_list *data, char **av)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	z = 0;
	data->stack_a = malloc(sizeof(int) * data->size_a);
	data->tmp_a = malloc(sizeof(int) * data->size_a);
	while (av[i])
	{
		j = 0;
		data->split = ft_split(av[i], ' ');
		while (data->split[j])
		{
			data->stack_a[z++] = ft_atoi(data->split[j]);
			j++;
		}
		free_split(data->split);
		i++;
	}
}

void	ft_space_control(char **av)
{
	int	flag;
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			ft_error();
		flag = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac >= 2)
	{
		ft_space_control(av);
		data = malloc(sizeof(t_list));
		control_size(data, av);
		fill_stack_a(data, av);
		have_same_number(data);
		sort_is_line(data);
		data_sort(data);
		if (data->size_a > 5)
			radix(data);
		else
			small_sort(data);
	}
}
