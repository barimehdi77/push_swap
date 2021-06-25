/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:35:44 by mbari             #+#    #+#             */
/*   Updated: 2021/06/25 11:41:05 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_select_instruction(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap_a_or_b(&stacks->stack_a, NO, 'a');
	else if (!ft_strcmp(line, "sb"))
		ft_swap_a_or_b(&stacks->stack_b, NO, 'b');
	else if (!ft_strcmp(line, "ss"))
		ft_swap_both(stacks, NO);
	else if (!ft_strcmp(line, "rra"))
		ft_reverse_rotate_a(&stacks->stack_a, NO);
	else if (!ft_strcmp(line, "rrb"))
		ft_reverse_rotate_b(&stacks->stack_b, NO);
	else if (!ft_strcmp(line, "rrr"))
		ft_reverse_rotate_both(stacks, NO);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate_a(&stacks->stack_a, NO);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate_b(&stacks->stack_b, NO);
	else if (!ft_strcmp(line, "rr"))
		ft_rotate_both(stacks, NO);
	else if (!ft_strcmp(line, "pa"))
		ft_push_a(stacks, NO);
	else if (!ft_strcmp(line, "pb"))
		ft_push_b(stacks, NO);
	else
		exit(ft_put_err(stacks, "Error", 0));
}
