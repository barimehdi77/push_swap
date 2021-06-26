# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbari <mbari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 15:34:01 by mbari             #+#    #+#              #
#    Updated: 2021/06/26 16:02:28 by mbari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable files
PUSH_SWAP = push_swap
CHECKER = checker


# Project's directories
PROJECTDIR = srcs
HEADERSDIR = $(PROJECTDIR)/headers
OBJECTSDIR = objects
OBJECTSCHECKERDIR = objects
PS_FOLDER = push_swap
CHECKER_FOLDER = checker
LIBFT_FOLDER = $(PROJECTDIR)/libft
LIBFT_HEADER = $(LIBFT_FOLDER)/libft.h
PS_HEADER = $(HEADERSDIR)/push_swap.h
CHECKER_HEADER = $(HEADERSDIR)/checker.h
GNL_HEADER = $(PROJECTDIR)/get_next_line/get_next_line.h


# Name of variables
LIBFT_LIB = libft.a
FLAGS = -Wall -Wextra -Werror
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m


# push_swap files variable
PS_FILES =  ft_check_errors.c \
ft_find_biggest_number.c \
ft_five_numbers.c \
ft_one_handred.c \
ft_pa_pb.c \
ft_push_swap.c \
ft_rra_rrb_rrr.c \
ft_sa_sb_ss_ra_rb_rr.c \
ft_sort_list.c \
ft_ten_numbers.c \
ft_three_numbers.c \

# checker files variable
CHECKER_FILES = ft_checker.c

# main file varible
MAIN_FILE = main.c

# get_next_line files varible
GNL_FILES = $(PROJECTDIR)/get_next_line/get_next_line.c

# Define objects for all sources
PS_OBJS := $(addprefix $(OBJECTSDIR)/$(PS_FOLDER)/, $(PS_FILES:.c=.o))
CHECKER_OBJS := $(addprefix $(OBJECTSCHECKERDIR)/$(CHECKER_FOLDER)/, $(CHECKER_FILES:.c=.o))
PS_MAIN_OBJ := $(addprefix $(PROJECTDIR)/$(PS_FOLDER)/, $(MAIN_FILE:.c=.o))
CHECKER_MAIN_OBJ := $(addprefix $(PROJECTDIR)/$(CHECKER_FOLDER)/, $(MAIN_FILE:.c=.o))
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

all: credit $(CHECKER) $(PUSH_SWAP)
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"
	@echo "         Made with love by : \033[1;91mmbari\033[m"
	
ft_libft:
	@echo "$(BLUE)████████████████████████ Making LIBFT ██████████████████████████$(RESET)"
	@$(MAKE) $(LIBFT_FOLDER)
	@echo "$(BLUE)███████████████████████ Making Push_swap ███████████████████████$(RESET)"

# push_swap making rules
$(PUSH_SWAP): ft_libft $(PS_OBJS) $(PS_MAIN_OBJ)
	@$(CC) -I $(PS_HEADER) -I $(LIBFT_HEADER) $(PS_OBJS) $(PS_MAIN_OBJ) $(LIBFT_FOLDER)/$(LIBFT_LIB) -o $@

$(OBJECTSDIR)/%.o: $(PROJECTDIR)/%.c $(PS_HEADER)
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -I $(PS_HEADER) -I $(LIBFT_HEADER) -o $@ -c $<

# checker making rules
print_line:
	@echo "$(BLUE)████████████████████████ Making checker ████████████████████████$(RESET)"

$(CHECKER): ft_libft $(PS_OBJS) print_line $(CHECKER_OBJS) $(CHECKER_MAIN_OBJ)
	@$(CC) -I $(PS_HEADER) -I $(CHECKER_HEADER) -I $(LIBFT_HEADER) -I $(GNL_HEADER) $(CHECKER_MAIN_OBJ) $(CHECKER_OBJS) \
		$(PS_OBJS) $(GNL_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) -o $@

$(OBJECTSCHECKERDIR)/%.o: $(PROJECTDIR)/%.c $(CHECKER_HEADER) $(PS_HEADER)
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -I $(PS_HEADER) -I $(LIBFT_HEADER) -o $@ -c $<

# Making main files
%.o: %.c
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -I $(PS_HEADER) -I $(CHECKER_HEADER) -I $(LIBFT_HEADER) -o $@ -c $<

# Remove all objects, dependencies and executable files generated during the build

clean:
	@echo "$(RED)deleting$(RESET): " $(OBJECTSDIR)
	@$(RMDIR) $(OBJECTSDIR) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " $(PS_MAIN_OBJ)
	@$(RMDIR) $(PS_MAIN_OBJ) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " $(CHECKER_MAIN_OBJ)
	@$(RMDIR) $(CHECKER_MAIN_OBJ) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " "libft objects"
	@$(MAKE) $(LIBFT_FOLDER) clean

fclean: clean
	@echo "$(RED)deleting$(RESET): " $(LIBFT_FOLDER)/$(LIBFT_LIB)
	@$(RM) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(ERRIGNORE)
	@echo "$(RED)deleting$(RESET): " $(PUSH_SWAP) 
	@echo "$(RED)deleting$(RESET): " $(CHECKER)
	@$(RM) $(PUSH_SWAP) $(CHECKER) $(ERRIGNORE)

re: fclean all

# Print Credit
credit:
	@echo "░▒█▀▀█░▒█░▒█░▒█▀▀▀█░▒█░▒█░░░▒█▀▀▀█░▒█░░▒█░█▀▀▄░▒█▀▀█"
	@echo "░▒█▄▄█░▒█░▒█░░▀▀▀▄▄░▒█▀▀█░░░░▀▀▀▄▄░▒█▒█▒█▒█▄▄█░▒█▄▄█"
	@echo "░▒█░░░░░▀▄▄▀░▒█▄▄▄█░▒█░▒█░░░▒█▄▄▄█░▒▀▄▀▄▀▒█░▒█░▒█░░░"
	@echo "         Made with love by : \033[1;91mmbari\033[m"
