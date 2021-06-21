/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:13 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 17:35:32 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "header/push_swap.h"


int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
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
	if (stacks->stack_a.vector)
		free(stacks->stack_a.vector);
	if (stacks->stack_b.vector)
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

int	ft_count_numbers(char	*string)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

t_stacks	ft_store_numbers(char *string)
{
	t_stacks	stacks;
	char		**numbers;
	int			number;
	int			size;
	int			i;

	i = 0;
	size = ft_count_numbers(string);
	
	stacks.stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks.stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks.stack_a.size = size;
	stacks.stack_b.size = size;
	stacks.stack_a.used_size = 0;
	stacks.stack_b.used_size = 0;
	numbers = ft_split(string, ' ');
	// free(string);
	while (numbers[i])
	{
		// printf("|%s---|\n", numbers[i]);
		// ft_putendl_fd(numbers[i], 1);
		if (!ft_isnumber(numbers[i]))
			exit(ft_put_err(&stacks, "Error 1", 0));
		number = ft_atoi(numbers[i]);
		if (!ft_isduplicate(&stacks, number))
			exit(ft_put_err(&stacks, "Error", 0));
		stacks.stack_a.vector[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

int		ft_av_size(char **av)
{
	int size;
	int i;
	
	i = 0;
	size = 0;
	while (av[i])
		size += ft_strlen(av[i++]) + 1;
	return (size);
}

char	*ft_av_to_string(char **av)
{
	char	*string;
	char 	*tmp;
	int		size;
	int 	i;
	int		j;
	
	i = 1;
	size = ft_av_size(av);
	string = NULL;
	while (av[i])
	{
		tmp = ft_strjoin(string, av[i]);
		string = ft_strjoin(tmp, " ");
		free (tmp);
		i++;
	}	
	printf("|%s|\n", string);
	return (string);
}

void	ft_print_stack_a(t_stacks *stacks)
{
	int i;

	i = 0;
	ft_putstr_fd(CYAN, 1);
	printf("/*****************************stack_a****************************/\n");
	while (i < stacks->stack_a.used_size)
	{
		printf("|size of stack_a= %d|used size = %d|value = %d|\n",stacks->stack_a.size, stacks->stack_a.used_size, stacks->stack_a.vector[i]);
		i++;
	}
	ft_putstr_fd(RESET, 1);
}

void	ft_print_stack_b(t_stacks *stacks)
{
	int i;
	
	i = 0;
	ft_putstr_fd(RED, 1);
	printf("/*****************************stack_b****************************/\n");
	while (i < stacks->stack_b.used_size)
	{
		printf("|size of stack_b = %d|used size = %d|value = %d|\n",stacks->stack_b.size, stacks->stack_b.used_size, stacks->stack_b.vector[i]);
		i++;
	}
	ft_putstr_fd(RESET, 1);
}

void	ft_print(t_stacks *stacks)
{
	int i;

	ft_print_stack_a(stacks);
	ft_print_stack_b(stacks);
}

int	ft_issorted(t_vector *vector)
{
	int i;
	int *tmp;

	i = 0;
	tmp = vector->vector;
	while (i < vector->used_size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;
	int			*arr;
	int			i;
	ac--;
	// ft_putnbr_fd(ac, 1);
	// create function gets the numbers in the arguments and stroe them in arr
	string = ft_av_to_string(av);
	// ft_putendl_fd(string,1 );
	stacks = ft_store_numbers(string);
	free(string);
	if (ft_issorted(&stacks.stack_a))
		return (ft_put_err(&stacks, NULL, 0));
	ft_print(&stacks);
	// ft_print_stack_a(&stacks);
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
	
	// // ft_putstr_fd(GREEN, 1);
	ft_print(&stacks);
	// // ft_putstr_fd(RESET, 1);
	
	// if (ft_issorted(&stacks.stack_a))
	// {
	// 	// ft_putstr_fd(GREEN, 1);
	// 	ft_putstr_fd("OK\n", 1);
	// 	// ft_putstr_fd(RESET, 1);
	// }
	// else
	// {
	// 	// ft_putstr_fd(RED, 1);
	// 	ft_putstr_fd("KO\n", 1);
	// 	// ft_putstr_fd(RESET, 1);
	// }
	return (ft_put_err(&stacks, NULL, 0));
}