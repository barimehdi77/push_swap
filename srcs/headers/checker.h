/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:57:42 by mbari             #+#    #+#             */
/*   Updated: 2021/06/25 11:41:16 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../headers/push_swap.h"
# include "../get_next_line/get_next_line.h"

void	ft_select_instruction(char *line, t_stacks *stacks);
void	ft_print(t_stacks *stacks);
void	ft_print_stack_b(t_stacks *stacks);
void	ft_print_stack_a(t_stacks *stacks);
#endif