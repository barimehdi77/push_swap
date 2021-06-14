/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:07:09 by mbari             #+#    #+#             */
/*   Updated: 2021/06/14 18:43:50 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_smallest_index(t_vector *stack_a)
{
	int i;
	int s_index;

	i = 0;
	s_index = i;
	while (i < stack_a->used_size)
	{
		if (stack_a->vector[s_index] > stack_a->vector[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	ft_find_smallest_number(t_stacks *stacks)
{
	int s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 2)
			ft_rotate_a(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_five_numbers(t_stacks *stacks)
{
	ft_find_smallest_number(stacks);
	ft_push_b(stacks);
	ft_find_smallest_number(stacks);
	ft_push_b(stacks);
	ft_sort_three_numbers(&stacks->stack_a);
	ft_push_a(stacks);
	ft_push_a(stacks);
	// ft_print(stacks);
}