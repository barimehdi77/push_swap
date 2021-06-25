/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:54:59 by mbari             #+#    #+#             */
/*   Updated: 2021/06/25 12:16:34 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define	YES 1
# define	NO 0

typedef struct s_vector
{
	int	*vector;
	int	size;
	int	used_size;
}				t_vector;

typedef struct s_stacks
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_stacks;

void		ft_sort_rest_of_numbers(t_stacks *stacks, int size);
int			ft_get_biggest_index(t_vector *stack_b);
void		ft_find_biggest_number(t_stacks *stacks);
int			ft_get_smallest_index(t_vector *stack_a);
void		ft_find_smallest_number(t_stacks *stacks);
void		ft_sort_five_numbers(t_stacks *stacks);
int			ft_search_index(t_stacks *stacks, int key_number);
void		ft_move_to_top(t_stacks *stacks, int index);
void		ft_push_index(t_stacks *stacks, int key_number);
void		ft_one_handred(t_stacks *stacks);
void		ft_five_handred(t_stacks *stacks);
void		ft_push_stack(int *vector, int used_size);
void		ft_pop_stack(int *vector, int used_size);
void		ft_push_a(t_stacks *stacks, int print);
void		ft_push_b(t_stacks *stacks, int print);
void		ft_reverse_rotate_a(t_vector *stack_a, int print);
void		ft_reverse_rotate_b(t_vector *stack_b, int print);
void		ft_reverse_rotate_both(t_stacks *stacks, int print);
void		ft_swap_a_or_b(t_vector *vector, int print, char stack);
void		ft_swap_both(t_stacks *stacks, int print);
void		ft_rotate_a(t_vector *stack_a, int print);
void		ft_rotate_b(t_vector *stack_b, int print);
void		ft_rotate_both(t_stacks *stacks, int print);
void		ft_swap(int *xp, int *yp);
int			*ft_list_init(t_vector *stack_a);
int			*ft_sort_array(t_vector *stack_a);
void		ft_sort_rest(t_stacks *stacks);
void		ft_sort_more_then_handred(t_stacks *stacks);
void		ft_find_smallest_number_ten(t_stacks *stacks);
void		ft_sort_ten_numbers(t_stacks *stacks);
void		ft_sort_three_numbers(t_vector *stack_a);
int			ft_isnumber(char *number);
int			ft_isduplicate(t_stacks *stacks, int number);
int			ft_issorted(t_vector *vector);
int			ft_count_numbers(char *string);
int			ft_put_err(t_stacks *stacks, char *message, int ret);
char		**ft_stacks_init(char *string, t_stacks *stacks);
t_stacks	ft_store_numbers(char *string);
int			ft_av_size(char **av);
char		*ft_av_to_string(char **av);
int			ft_find_key_number(int *sorted_list, int size,
				int divided, int chunks);

#endif