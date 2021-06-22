/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:19:23 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 17:19:42 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../get_next_line/get_next_line.h"

int main(int ac, char **av)
{
	char	*line;
	t_stacks	stacks;
	char	*string;
	int ret;
	
	ac--;
	string = ft_av_to_string(av);
	stacks = ft_store_numbers(string);
	// ft_print(&stacks);
	line = NULL;
	ret = 0;
	// ft_print(&stacks);
	while (get_next_line(0, &line) == 1)
	{
		ft_select_instruction(line, &stacks);
		// ft_putendl_fd(line, 1);
		free(line);
	}
	ft_print(&stacks);
}
