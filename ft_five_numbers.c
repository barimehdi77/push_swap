/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 17:07:09 by mbari             #+#    #+#             */
/*   Updated: 2021/06/14 17:18:42 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_numbers(t_stacks *stacks)
{
	ft_push_b(stacks);
	ft_push_b(stacks);
			ft_print(stacks);
	ft_sort_three_numbers(&stacks->stack_a);
			ft_print(stacks);
	ft_push_a(stacks);
			ft_print(stacks);
	ft_rotate_a(&stacks->stack_a, YES);
			ft_print(stacks);
	ft_push_a(stacks);
			ft_print(stacks);
	ft_rotate_a(&stacks->stack_a, YES);
			ft_print(stacks);
}