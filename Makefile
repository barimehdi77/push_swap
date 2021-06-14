# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 15:34:01 by mbari             #+#    #+#              #
#    Updated: 2021/06/14 17:11:52 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell

SRC_EXECUTE= main.c ft_inctructions.c ft_three_numbers.c ft_five_numbers.c

LIBFT= libft/libft.a

# *****     flags     ***** #

COM= gcc
CFLAGE= #-Wall -Wextra -Werror

all: libft $(NAME)

libft:
	@make -sC libft/

$(NAME):
	@$(COM) -g $(CFLAGE) $(SRC_MAIN) $(SRC_PARSE) $(SRC_EXECUTE) $(LIBFT) -g -lncurses