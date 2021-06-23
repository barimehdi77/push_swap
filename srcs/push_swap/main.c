/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:07:55 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 19:45:57 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;

	ac--;
	if (ac == 0)
		return (0);
	string = ft_av_to_string(av);
	stacks = ft_store_numbers(string);
	if (ft_issorted(&stacks.stack_a))
		return (ft_put_err(&stacks, NULL, 0));
	if (stacks.stack_a.size == 2)
		ft_swap_a_or_b(&stacks.stack_a, YES, 'a');
	if (stacks.stack_a.size == 3)
		ft_sort_three_numbers(&stacks.stack_a);
	if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
		ft_sort_five_numbers(&stacks);
	if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		ft_sort_ten_numbers(&stacks);
	if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		ft_one_handred(&stacks);
	if (stacks.stack_a.size > 100)
		ft_five_handred(&stacks);
	return (ft_put_err(&stacks, NULL, 0));
}
