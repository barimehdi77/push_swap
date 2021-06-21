/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_handred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:14:10 by kali              #+#    #+#             */
/*   Updated: 2021/06/21 13:09:55 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void ft_swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int *ft_sort_array(t_vector *stack_a)
{
    int i;
    int j;
    int temp;
	int min_index;
    int *sorted_list;

    i = 0;
    sorted_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		sorted_list[i] = stack_a->vector[i];
		i++;
	}
	i = 0;
    while (i < stack_a->size - 1)
    {
		min_index = i;
        j = i + 1;
        while (j < stack_a->size)
        {
            if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
            j++;
        }
		ft_swap(&sorted_list[min_index], &sorted_list[i]);
        i++;
    }
    return (sorted_list);
}


int ft_find_key_number(int *sorted_list, int size, int divided, int chunks)
{
	int key_munber;
	
	key_munber = sorted_list[(size * divided) / chunks];
    return(key_munber);
}

int ft_search_index(t_stacks *stacks, int key_number)
{
    int i;

    i = 0;
    while (i < stacks->stack_a.used_size)
    {
        if (stacks->stack_a.vector[i] <= key_number)
            return (i);
        i++;
    }
    return (-1);
}

void    ft_move_to_top(t_stacks *stacks, int index)
{
    int divid;

	divid = stacks->stack_a.used_size / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ft_rotate_a(&stacks->stack_a, YES);
			index--;
		}
		else
		{
			ft_reverse_rotate_a(&stacks->stack_a, YES);
			index++;
			if (index == stacks->stack_a.used_size)
				break;
		}
	}
}

void    ft_push_index(t_stacks *stacks, int key_number)
{
    int index;

    index = ft_search_index(stacks, key_number);
    while (index != -1)
    {
        ft_move_to_top(stacks, index);
		ft_push_b(stacks);
        index = ft_search_index(stacks, key_number);
    }
}

void	ft_sort_ten_numbers2(t_stacks *stacks, int size)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size >= 5)
		{
			// ft_putnbr_fd(stacks->stack_a.used_size, 1);
			ft_find_smallest_number2(stacks);
			ft_push_b(stacks);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != size)
			ft_push_a(stacks);
	}
}

int		ft_get_biggest_index(t_vector *stack_b)
{
	int i;
	int b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->used_size)
	{
		if (stack_b->vector[b_index] < stack_b->vector[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	ft_find_biggest_number(t_stacks *stacks)
{
	int b_index;

	b_index = ft_get_biggest_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.used_size / 2))
			ft_rotate_b(&stacks->stack_b, YES);
		else
			ft_reverse_rotate_b(&stacks->stack_b, YES);
		b_index = ft_get_biggest_index(&stacks->stack_b);
	}
}

void	ft_one_handred(t_stacks *stacks)
{
	int i;
	int key_number;
	int *sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	ft_print(&stacks);
	while (i != 4)
	{
		key_number = ft_find_key_number(sorted_list, stacks->stack_a.size, i, 4);
		ft_push_index(stacks, key_number);
		i++;
	}
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, YES, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	if (stacks->stack_a.used_size > 5)
		ft_sort_ten_numbers2(stacks, stacks->stack_a.used_size);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks);
	}
}

void	ft_five_handred(t_stacks *stacks)
{
	int i;
	int key_number;
	int *sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 8)
	{
		key_number = ft_find_key_number(sorted_list, stacks->stack_a.size, i, 8);
		ft_push_index(stacks, key_number);
		i++;
	}
	// ft_print_stack_a(stacks);
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, YES, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		ft_sort_ten_numbers2(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		ft_one_handred(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks);
	}
}