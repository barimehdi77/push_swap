/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:35:44 by mbari             #+#    #+#             */
/*   Updated: 2021/06/22 07:53:02 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"
#include "get_next_line/get_next_line.h"

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

int	ft_isduplicate(t_stacks *stacks, int number)
{
	int	size;
	int	i;

	i = 0;
	size = stacks->stack_a.used_size;
	if (size == 0)
		return (1);
	while (i < size)
	{
		if (stacks->stack_a.vector[i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_issorted(t_vector *vector)
{
	int	i;
	int	*tmp;

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

int	ft_count_numbers(char *string)
{
	int	i;
	int	count;

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

char	**ft_stacks_init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free (string);
	return (numbers);
}

t_stacks	ft_store_numbers(char *string)
{
	t_stacks			stacks;
	char				**numbers;
	long long			number;
	int					size;
	int					i;

	i = 0;
	numbers = ft_stacks_init(string, &stacks);
	while (numbers[i])
	{
		if (!ft_isnumber(numbers[i]))
			exit(ft_put_err(&stacks, "Error", 0));
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(ft_put_err(&stacks, "Error", 0));
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

int	ft_av_size(char **av)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (av[i])
		size += ft_strlen(av[i++]) + 1;
	return (size);
}

char	*ft_av_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		size;
	int		i;
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

void	ft_select_instruction(char *line, t_stacks *stacks)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap_a_or_b(&stacks->stack_a, YES, 'a');
	else if (!ft_strcmp(line, "sb"))
		ft_swap_a_or_b(&stacks->stack_b, YES, 'b');
	else if (!ft_strcmp(line, "ss"))
		ft_swap_both(stacks);
	else if (!ft_strcmp(line, "rra"))
		ft_reverse_rotate_a(&stacks->stack_a, YES);
	else if (!ft_strcmp(line, "rrb"))
		ft_reverse_rotate_b(&stacks->stack_b, YES);
	else if (!ft_strcmp(line, "rrr"))
		ft_reverse_rotate_both(stacks);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate_a(&stacks->stack_a, YES);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate_b(&stacks->stack_b, YES);
	else if (!ft_strcmp(line, "rr"))
		ft_rotate_both(stacks);
	else if (!ft_strcmp(line, "pa"))
		ft_push_a(stacks);
	else if (!ft_strcmp(line, "pb"))
		ft_push_b(stacks);
	else
		exit(ft_put_err(stacks, "Error", 0));
}

int main(int ac, char **av)
{
	char	*line;
	t_stacks	stacks;
	char	*string;
	int ret;
	
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