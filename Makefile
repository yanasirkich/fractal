# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 13:33:17 by ysirkich          #+#    #+#              #
#    Updated: 2024/10/29 19:51:19 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fractol
CC = gcc
RM = rm -f
CFLAGS = -Wall	-Wextra	-Werror -g
INCLUDE	=-I. -I$(LIBFT_DIR) -I$(LIBMLX_DIR)

LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBS = -L$(LIBFT_DIR) $(LIBMLX) -ldl -lm -lglfw -lGL

# Source directories
SRCS_DIR = srcs

# Source files
SRCS =	$(SRCS_DIR)/main.c		\
		$(SRCS_DIR)/fractals.c	\
		$(SRCS_DIR)/render.c	\
		$(SRCS_DIR)/innit.c		\
		$(SRCS_DIR)/events.c	\
		# dont forget to add all files at some point 

# Object files
OBJ = $(SRCS:.c=.o)

# Rues 
.c.o:
	@echo "Compiling $<..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

$(NAME):	$(OBJ)	$(LIBFT)	$(LIBMLX)
			@echo "Linking stuff..."
			@$(CC)	$(CFLAGS)	$(OBJ)	$(LIBS)	-o	$(NAME)
			@echo "$(NAME) created successfully!"
$(LIBFT):
		@echo "Building libft..."
		@$(MAKE)	-C	$(LIBFT_DIR)
$(LIBMLX):
	@mkdir -p $(LIBMLX_DIR)/build
	@cd $(LIBMLX_DIR)/build && cmake .. && make

all	: libft libmlx	$(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM)	$(OBJ)
	@$(MAKE)	-C	$(LIBFT_DIR) clean
	@$(MAKE)	-C $(LIBMLX_DIR)/build clean

fclean:
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBMLX_DIR)/build fclean

re: fclean all

.PHONY: all libft libmlx clean fclean re