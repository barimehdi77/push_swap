/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:15:31 by mbari             #+#    #+#             */
/*   Updated: 2021/06/25 11:30:39 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
	int	i;

	i = 0;
	while (i < used_size)
	{
		vector[i] = vector[i + 1];
		i++;
	}
}

void	ft_push_a(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == YES)
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

void	ft_push_b(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == YES)
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
