/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inctructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:15:31 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 09:45:55 by mbari            ###   ########.fr       */
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

// void	ft_swap_b(t_vector *vector, int print)
// {
// 	int	temp;

// 	if (print == YES)
// 		ft_putendl_fd("sb", 1);
// 	if (vector->used_size > 1)
// 	{
// 		temp = vector->vector[0];
// 		vector->vector[0] = vector->vector[1];
// 		vector->vector[1] = temp;
// 	}
// }

void	ft_swap_both(t_stacks *stacks)
{
	ft_putendl_fd("ss", 1);
	ft_swap_a_or_b(&stacks->stack_a, NO, 'a');
	ft_swap_a_or_b(&stacks->stack_b, NO, 'b');
}

void	ft_push_stack(int *vector, int used_size)
{
	while (used_size > 0)
	{
		vector[used_size] = vector[used_size - 1];
		used_size--;
	}
}

void	ft_pop_stack(int *vector, int used_size)
{
	int i;

	i = 0;
	while (i < used_size)
	{
		vector[i] = vector[i + 1];
		i++;
	}
}

void	ft_push_a(t_stacks *stacks)
{
	int used_size_b;
	int used_size_a;
	int i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	ft_putendl_fd("pa", 1);
	if (used_size_b == 0)
		return ;
	if (used_size_a == 0)
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	else
	{
		ft_push_stack(stacks->stack_a.vector, used_size_a);
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	}
	ft_pop_stack(stacks->stack_b.vector, used_size_b);
	stacks->stack_a.used_size++;
	stacks->stack_b.used_size--;
}

void	ft_push_b(t_stacks *stacks)
{
	int used_size_b;
	int used_size_a;
	int i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	ft_putendl_fd("pb", 1);
	if (used_size_a == 0)
		return ;
	if (used_size_b == 0)
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	else
	{
		ft_push_stack(stacks->stack_b.vector, used_size_b);
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	}
	ft_pop_stack(stacks->stack_a.vector, used_size_a);
	stacks->stack_b.used_size++;
	stacks->stack_a.used_size--;
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
		ft_putendl_fd("ra", 1);
	first_element = stack_b->vector[0];
	ft_pop_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[stack_b->used_size - 1] = first_element;
}

void	ft_rotate_both(t_stacks *stacks)
{
	ft_putendl_fd("rr", 1);
	ft_rotate_a(&stacks->stack_a, NO);
	ft_rotate_b(&stacks->stack_b, NO);
}

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

void	ft_reverse_rotate_both(t_stacks *stacks)
{
	ft_putendl_fd("rrr", 1);
	ft_reverse_rotate_a(&stacks->stack_a, NO);
	ft_reverse_rotate_b(&stacks->stack_b, NO);
}