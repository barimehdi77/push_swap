# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 15:34:01 by mbari             #+#    #+#              #
#    Updated: 2021/06/22 17:03:41 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME = push_swap

# Project's directories
SOURCEDIR := src
HEADERDIR := header
OBJECTSDIR := objects
OBJECTSBONUSDIR := objects
SRC_FOLDER = src
BONUS_FOLDER = bonus
LIBFT_FOLDER = libft
LIBFT_HEADER = $(LIBFT_FOLDER)/libft.h
SRCHEADER = $(HEADERDIR)/push_swap.h


# Name of variables
LIBFT_LIB = libft.a
FLAGS = -Wall -Wextra -Werror
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m


# Execution files variable
SRC_FILES =  ft_check_errors.c \
ft_find_biggest_number.c \
ft_five_numbers.c \
ft_one_handred.c \
ft_pa_pb.c \
ft_push_swap.c \
ft_rra_rrb_rrr.c \
ft_sa_sb_ss_ra_rb_rr.c \
ft_sort_list.c \
ft_ten_numbers.c \
ft_three_numbers.c 

# Lexer files variable

BONUS_FILES = ft_checker.c

# Define objects for all sources
SRC_OBJS := $(addprefix $(OBJECTSDIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS := $(addprefix $(OBJECTSBONUSDIR)/, $(BONUS_FILES:.c=.o))
LIBFT_FILE := $(LIBFT_FOLDER)/$(LIBFT_LIB)

# Name the compiler
CC = gcc

# OS specific part
RM = rm -rf 
RMDIR = rm -rf 
MKDIR = mkdir -p
MAKE = make -C
ECHO = /bin/echo
ERRIGNORE = 2>/dev/null


.PHONY: all fclean

all: credit $(NAME)
	
ft_libft:
	@echo "$(BLUE)█████████████████████████ Making LIBFT █████████████████████████$(RESET)"
	@$(MAKE) $(LIBFT_FOLDER)
	@echo "$(BLUE)███████████████████████ Making minishell ███████████████████████$(RESET)"


$(NAME): ft_libft $(SRC_OBJS)
	@$(CC) -I $(SRCHEADER) -I $(LIBFT_HEADER) $(SRC_OBJS) $(LIBFT_FOLDER)/$(LIBFT_LIB) -o $@
	@echo "$(BLUE)███████████████████████ Compiling is DONE ██████████████████████$(RESET)"
	@echo "         Made with love by : \033[1;91mmbari\033[m"

$(CHECKER): ft_libft $(NAME) $(BONUS_OBJS)
	@$(CC) -I $(BONUSHEADER) -I $(LIBFT_HEADER) $(BONUS_OBJS) $(SRC_OBJS) get_next_line/*.c $(LIBFT_FOLDER)/$(LIBFT_LIB)
	@echo "$(BLUE)███████████████████████ Compiling is DONE ██████████████████████$(RESET)"
	@echo "         Made with love by : \033[1;91mmbari\033[m"

$(OBJECTSDIR)/%.o: $(SOURCEDIR)/%.c $(SRCHEADER)
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -I $(SRCHEADER) -I $(LIBFT_HEADER) -o $@ -c $<

$(OBJECTSBONUSDIR)/%.o: $(BONUS_FOLDER)/%.c $(SRCHEADER)
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -I $(SRCHEADER) -I $(LIBFT_HEADER) -o $@ -c $<

# Remove all objects, dependencies and executable files generated during the build

clean:
	@echo "$(RED)deleting$(RESET): " $(OBJECTSDIR)
	@$(RMDIR) src/*.o $(OBJECTSDIR) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " "libft objects"
	@$(MAKE) $(LIBFT_FOLDER) clean

fclean: clean
	@echo "$(RED)deleting$(RESET): " $(LIBFT_FOLDER)/$(LIBFT_LIB)
	@$(RM) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " $(NAME)
	@$(RM) $(NAME) $(ERRIGNORE)

re: fclean $(NAME)

credit:
	@echo "░▒█▀▀█░▒█░▒█░▒█▀▀▀█░▒█░▒█░░░▒█▀▀▀█░▒█░░▒█░█▀▀▄░▒█▀▀█"
	@echo "░▒█▄▄█░▒█░▒█░░▀▀▀▄▄░▒█▀▀█░░░░▀▀▀▄▄░▒█▒█▒█▒█▄▄█░▒█▄▄█"
	@echo "░▒█░░░░░▀▄▄▀░▒█▄▄▄█░▒█░▒█░░░▒█▄▄▄█░▒▀▄▀▄▀▒█░▒█░▒█░░░"
	@echo "         Made with love by : \033[1;91mmbari\033[m"
