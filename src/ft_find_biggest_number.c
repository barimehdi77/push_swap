/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_biggest_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:14:55 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 18:16:59 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_rest_of_numbers(t_stacks *stacks, int size)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size >= 5)
		{
			ft_find_smallest_number2(stacks);
			ft_push_b(stacks);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != size)
			ft_push_a(stacks);
	}
}

int	ft_find_key_number(int *sorted_list, int size, int divided, int chunks)
{
	int	key_munber;

	key_munber = sorted_list[(size * divided) / chunks];
	return (key_munber);
}

int	ft_get_biggest_index(t_vector *stack_b)
{
	int	i;
	int	b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->used_size)
	{
		if (stack_b->vector[b_index] < stack_b->vector[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	ft_find_biggest_number(t_stacks *stacks)
{
	int	b_index;

	b_index = ft_get_biggest_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.used_size / 2))
			ft_rotate_b(&stacks->stack_b, YES);
		else
			ft_reverse_rotate_b(&stacks->stack_b, YES);
		b_index = ft_get_biggest_index(&stacks->stack_b);
	}
}
