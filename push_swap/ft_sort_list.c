/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:13:01 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 16:10:49 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*ft_list_init(t_vector *stack_a)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		sorted_list[i] = stack_a->vector[i];
		i++;
	}
	return (sorted_list);
}

int	*ft_sort_array(t_vector *stack_a)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_list;

	i = 0;
	sorted_list = ft_list_init(stack_a);
	while (i < stack_a->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
			j++;
		}
		ft_swap(&sorted_list[min_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

void	ft_sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, YES, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	if (stacks->stack_a.used_size > 5)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
}

void 	ft_sort_more_then_handred(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, YES, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		ft_one_handred(stacks);
}
