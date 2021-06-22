/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:19:23 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 20:46:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

int	main(int ac, char **av)
{
	char		*line;
	t_stacks	stacks;
	char		*string;
	int			ret;

	ac--;
	if (ac == 0)
		return (0);
	string = ft_av_to_string(av);
	stacks = ft_store_numbers(string);
	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_select_instruction(line, &stacks);
		free(line);
	}
	if (!ft_issorted(&stacks.stack_a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}
