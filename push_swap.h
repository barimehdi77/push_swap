/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:54:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/09 21:12:53 by mbari            ###   ########.fr       */
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



void	ft_swap_a(t_stacks *stacks, int print);
void	ft_swap_b(t_stacks *stacks, int print);
void	ft_swap_both(t_stacks *stacks);
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);
void	ft_rotate_a(t_vector *stack_a, int print);
void	ft_rotate_b(t_vector *stack_b, int print);