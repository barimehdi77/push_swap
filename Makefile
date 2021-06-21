# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 15:34:01 by mbari             #+#    #+#              #
#    Updated: 2021/06/21 20:21:56 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRC_EXECUTE= src/*.c

LIBFT= libft/libft.a

# *****     flags     ***** #

COM= gcc
CFLAGE= #-Wall -Wextra -Werror

all: libft $(NAME)

libft:
	@make -sC libft/

$(NAME):
	@$(COM) -g $(CFLAGE) $(SRC_MAIN) $(SRC_PARSE) $(SRC_EXECUTE) $(LIBFT) -o $(NAME) -g -lncurses

fclen:
	rm -rf push_swap*

re: fclen $(NAME)