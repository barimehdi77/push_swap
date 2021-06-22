/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:11:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 21:09:32 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_reverse_rotate_a(t_vector *stack_a, int print)
{
	int	last_element;

	if (print == YES)
		ft_putendl_fd("rra", 1);
	last_element = stack_a->vector[stack_a->used_size - 1];
	ft_push_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[0] = last_element;
}

void	ft_reverse_rotate_b(t_vector *stack_b, int print)
{
	int	last_element;

	if (print == YES)
		ft_putendl_fd("rrb", 1);
	last_element = stack_b->vector[stack_b->used_size - 1];
	ft_push_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[0] = last_element;
}

void	ft_reverse_rotate_both(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("rrr", 1);
	ft_reverse_rotate_a(&stacks->stack_a, NO);
	ft_reverse_rotate_b(&stacks->stack_b, NO);
}
