# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 13:33:17 by ysirkich          #+#    #+#              #
#    Updated: 2024/10/28 22:20:30 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fractol
CC = gcc
RM = rm -f
CFLAGS = -Wall	-Wextra	-Werror -g
INCLUDE	=-I. -Iincludes -Ilibft -Ilib/MLX42/include

LIBMLX = ./lib/MLX42

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR)	-lft	-L$(LIBMLX) -lmlx42

# Source directories
SRCS_DIR = srcs

# Source files
SRCS =	$(SRCS_DIR)/main.c	\
		$(SRCS_DIR)/fractals.c	\
		$(SRCS_DIR)/render.c	\
		$(SRCS_DIR)/innit.c	\
		# dont forget to add all files at some point 

# Object files
OBJ = $(SRCS:.c=.o)

# Rues 
.c.o:
	@echo "Compiling $<..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

$(NAME):	$(OBJ)	$(LIBFT)
			@echo "Linking stuff..."
			@$(CC)	$(CFLAGS)	$(OBJ)	$(LIBS)	-o	$(NAME)
			@echo "$(NAME) created successfully!"
$(LIBFT):
		@echo "Building libft..."
		@$(MAKE)	-C	$(LIBFT_DIR)

all	:	$(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM)	$(OBJ)
	@$(MAKE)	-C	$(LIBFT_DIR) clean

fclean:
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 