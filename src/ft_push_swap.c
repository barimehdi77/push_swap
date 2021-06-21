/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:13 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 20:34:26 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	t_stacks	stacks;
	char		**numbers;
	int			number;
	int			size;
	int			i;

	i = 0;
	numbers = ft_stacks_init(string, &stacks);
	while (numbers[i])
	{
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

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;
	int			*arr;
	int			i;

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
