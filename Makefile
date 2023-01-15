# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 14:44:21 by zsyyida           #+#    #+#              #
#    Updated: 2022/10/04 10:11:27 by zsyyida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# push_swap's executable
NAME = push_swap

#make directories
INC_DIR = include
SRC_DIR = sources
OBJ_DIR = object
LIBFT_DIR = libft
# libft.a is the library so has .a at end
LIBFT = libft.a

# ARG="4 1 0 2 3"; ./push_swap $ARG | ./checker $ARG
# ARG="4 1 0 2 3"; ./push_swap $ARG | wc -l

SRCS = main.c ft_check_empty.c find_error.c ft_operations_push.c ft_operations_rotate.c\
	ft_operations_rev_rotate.c ft_operations_swap.c ft_sort.c\
	ft_utilities1.c ft_min_max.c ft_utilities2.c sort_five.c\
	ft_sort_upto100.c ft_utilities_100.c ft_sort_upto_500.c
#will add all object files into a directory one above
# %o: %c same as .c=.o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC	= gcc -g
RM	= rm -rf

CFLAGS = -Wall -Wextra -Werror

#to create all of the .o files from files in SRC_DIR in OBJ_DIR
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@
#because the include directory for libft  is in libft.

all:	$(NAME)

# goes to file -L
# looks for library -l .All libraries have lib so ft
# this is especially important in linux. Even the order.
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -Llibft -lft -o push_swap
	@echo "push_swap ready"
#"-c $< -o $@" is equivalent to "$(OBJ_SRC) -o pushswap"
# -C changes the path
$(LIBFT):
	@make all -C $(LIBFT_DIR)

# -o turns object files into executable (coming after it)
# @make will go to and use libft makefile to make libft
#adding an @ before a command stops it from being printed

#make vis will run visualiser
vis: re
	@/usr/bin/python3 ./python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	
clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "object files removed"
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "object files and binary removed"

re:	fclean all
	@echo "object files and binary removed and binary remade"

# to remove all recipes that aren't files to avoid relinking
.PHONY:		all clean fclean re
