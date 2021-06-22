/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss_ra_rb_rr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:10:06 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 21:10:38 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap_a_or_b(t_vector *vector, int print, char stack)
{
	int	temp;

	if (print == YES && stack == 'a')
		ft_putendl_fd("sa", 1);
	else if (print == YES && stack == 'b')
		ft_putendl_fd("sb", 1);
	if (vector->used_size > 1)
	{
		temp = vector->vector[0];
		vector->vector[0] = vector->vector[1];
		vector->vector[1] = temp;
	}
}

void	ft_swap_both(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("ss", 1);
	ft_swap_a_or_b(&stacks->stack_a, NO, 'a');
	ft_swap_a_or_b(&stacks->stack_b, NO, 'b');
}

void	ft_rotate_a(t_vector *stack_a, int print)
{
	int	first_element;

	if (print == YES)
		ft_putendl_fd("ra", 1);
	first_element = stack_a->vector[0];
	ft_pop_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[stack_a->used_size - 1] = first_element;
}

void	ft_rotate_b(t_vector *stack_b, int print)
{
	int	first_element;

	if (print == YES)
		ft_putendl_fd("rb", 1);
	first_element = stack_b->vector[0];
	ft_pop_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[stack_b->used_size - 1] = first_element;
}

void	ft_rotate_both(t_stacks *stacks, int print)
{
	if (print == YES)
		ft_putendl_fd("rr", 1);
	ft_rotate_a(&stacks->stack_a, NO);
	ft_rotate_b(&stacks->stack_b, NO);
}
