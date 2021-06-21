/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:54:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/21 09:56:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
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



int		ft_issorted(t_vector *vector);
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
int		ft_get_smallest_index(t_vector *stack_a);
void	ft_find_smallest_number2(t_stacks *stacks);
void	ft_sort_ten_numbers(t_stacks *stacks);
void	ft_one_handred(t_stacks *stacks);
void	ft_five_handred(t_stacks *stacks);


char	*ft_av_to_string(char **av);
t_stacks	ft_store_numbers(char *string);