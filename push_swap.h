/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:54:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/14 17:16:14 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define	YES 1
#define	NO 0


typedef struct	s_vector
{
	int	*vector;
	int size;
	int used_size;
}				t_vector;

typedef struct 	s_stacks
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_stacks;

/********************PRINT***************************/
void	ft_print(t_stacks *stacks);
void	ft_print_stack_a(t_stacks *stacks);
void	ft_print_stack_b(t_stacks *stacks);
/***************************************************/




void	ft_swap_a_or_b(t_vector *vector, int print, char stack);
void	ft_swap_both(t_stacks *stacks);
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);
void	ft_rotate_a(t_vector *stack_a, int print);
void	ft_rotate_b(t_vector *stack_b, int print);
void	ft_rotate_both(t_stacks *stacks);
void	ft_reverse_rotate_a(t_vector *stack_a, int print);
void	ft_reverse_rotate_b(t_vector *stack_b, int print);
void	ft_reverse_rotate_both(t_stacks *stacks);
void	ft_sort_three_numbers(t_vector *stack_a);
void	ft_sort_five_numbers(t_stacks *stacks);