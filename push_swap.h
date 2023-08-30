/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:50:13 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/29 16:48:29 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	**split;
	int		size_a;
	int		size_b;
	int		size_tmp;
	int		*stack_a;
	int		*stack_b;
	int		*tmp_a;
	int		temp;
	char	**checks;
	int		minsize;

}			t_list;

char		**ft_split(char const *s, char c);
void		control_size(t_list *data, char **av);
void		fill_stack_a(t_list *data, char **av);
int			have_same_number(t_list *data);
long		ft_atoi(char *str);
int			sort_is_line(t_list *data);
void		swap_sa(t_list *data);
void		swap_sb(t_list *data);
void		swap_ss(t_list *data);
void		swap_ra(t_list *data);
void		swap_rb(t_list *data);
void		swap_rr(t_list *data);
void		swap_rra(t_list *data);
void		swap_rrb(t_list *data);
void		swap_rrr(t_list *data);
void		push_a(t_list *data);
void		push_b(t_list *data);
void		data_sort(t_list *data);
void		two_sort(t_list *data);
void		three_sort(t_list *data);
void		greater_than_three(t_list *data);
void		up_side(int *arr, int len);
void		minpush(t_list *list);
void		small_sort(t_list *data);
void		radix(t_list *data);
int			bit(t_list *data);
void		radixidx(t_list *data);
int			find_index(int *arr, int value);
int			error_message(void);
void		ft_error(void);
int			ft_isdigit(int c);

#endif
