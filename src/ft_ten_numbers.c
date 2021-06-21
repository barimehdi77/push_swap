/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:57:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 18:07:20 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_find_smallest_number2(t_stacks *stacks)
{
	int	s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ft_rotate_a(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_ten_numbers(t_stacks *stacks)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size != 5)
		{
			ft_find_smallest_number2(stacks);
			ft_push_b(stacks);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != stacks->stack_a.size)
			ft_push_a(stacks);
	}
}
