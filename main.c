/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:13 by mbari             #+#    #+#             */
/*   Updated: 2021/06/08 20:55:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"


int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_put_err(t_stacks *stacks, char *message, int ret)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	ft_putendl_fd(message, 2);
	return (ret);
}

int ft_isduplicate(t_stacks *stacks, int number)
{
	int size;

	size = stacks->arr_size;
	while (size >= 0)
	{
		if (stacks->stack_a[size] == number)
			return (0);
		size--;
	}
	return (1);
}

t_stacks	ft_store_numbers(int size, char **av)
{
	t_stacks	stacks;
	int			number;
	int			i;

	i = 0;
	stacks.stack_a = (int *)malloc(sizeof(int) * size);
	stacks.stack_b = (int *)malloc(sizeof(int) * size);
	stacks.arr_size = size;
	while (*av)
	{
		if (!ft_isnumber(*av))
			exit(ft_put_err(&stacks, ft_strjoin(ft_strjoin("Error: ", *av), " Not a number"), 0));
		number = ft_atoi(*av);
		if (!ft_isduplicate(&stacks, number))
			exit(ft_put_err(&stacks, ft_strjoin(ft_strjoin("Error: ", *av), " is duplicated"), 0));
		stacks.stack_a[i++] = ft_atoi(*av++);
	}
	return (stacks);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	int			*arr;
	int			i;
	// create function gets the numbers in the arguments and stroe them in arr
	stacks = ft_store_numbers(ac - 1, av + 1);
	i = 0;
	while (i < stacks.arr_size)
		printf("%d|%d|\n",ac, stacks.stack_a[i++]);
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}