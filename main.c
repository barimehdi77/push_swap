/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:13 by mbari             #+#    #+#             */
/*   Updated: 2021/06/09 21:07:26 by mbari            ###   ########.fr       */
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
	free(stacks->stack_a.vector);
	free(stacks->stack_b.vector);
	if (message != NULL)
		ft_putendl_fd(message, 2);
	return (ret);
}

int ft_isduplicate(t_stacks *stacks, int number)
{
	int size;

	size = stacks->stack_a.used_size;
	while (size >= 0)
	{
		if (stacks->stack_a.vector[size] == number)
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
	stacks.stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks.stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks.stack_a.size = size;
	stacks.stack_b.size = size;
	stacks.stack_a.used_size = 0;
	stacks.stack_b.used_size = 0;
	while (*av)
	{
		if (!ft_isnumber(*av))
			exit(ft_put_err(&stacks, ft_strjoin(ft_strjoin("Error: ", *av), " Not a number"), 0));
		number = ft_atoi(*av);
		if (!ft_isduplicate(&stacks, number))
			exit(ft_put_err(&stacks, ft_strjoin(ft_strjoin("Error: ", *av), " is duplicated"), 0));
		stacks.stack_a.vector[i++] = ft_atoi(*av++);
		stacks.stack_a.used_size++;
	}
	return (stacks);
}

void	ft_print_stack_a(t_stacks *stacks)
{
	int i;

	i = 0;
	printf("/*****************************stack_a****************************/\n");
	while (i < stacks->stack_a.used_size)
	{
		printf("|size of stack_a= %d|used size = %d|value = %d|\n",stacks->stack_a.size, stacks->stack_a.used_size,  stacks->stack_a.vector[i]);
		i++;
	}
}

void	ft_print_stack_b(t_stacks *stacks)
{
	int i;

	printf("/*****************************stack_b****************************/\n");
	i = 0;
	while (i < stacks->stack_b.used_size)
	{
		printf("|size of stack_b = %d|used size = %d|value = %d|\n",stacks->stack_b.size, stacks->stack_b.used_size, stacks->stack_b.vector[i]);
		i++;
	}
}

void	ft_print(t_stacks *stacks)
{
	int i;

	ft_print_stack_a(stacks);
	ft_print_stack_b(stacks);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	int			*arr;
	int			i;
	// create function gets the numbers in the arguments and stroe them in arr
	stacks = ft_store_numbers(ac - 1, av + 1);
	ft_print(&stacks);
	//ft_swap_a(&stacks, YES);
	ft_push_b(&stacks, YES);
	ft_push_b(&stacks, YES);
	ft_push_b(&stacks, YES);
	ft_push_b(&stacks, YES);
	ft_push_b(&stacks, YES);
	// printf("after swaping\n");
	// ft_print(&stacks);
	// ft_push_a(&stacks, YES);
	// ft_push_a(&stacks, YES);
	// ft_push_a(&stacks, YES);
	// ft_print(&stacks);
	ft_print_stack_b(&stacks);
	ft_rotate_b(&stacks.stack_b, YES);
	ft_print_stack_b(&stacks);
	
	return (ft_put_err(&stacks, NULL, 0));
}