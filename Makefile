# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 13:33:17 by ysirkich          #+#    #+#              #
#    Updated: 2024/11/04 02:26:20 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fractol
CC = gcc
RM = rm -f
CFLAGS = -Wall	-Wextra	-Werror -g
INCLUDE	=-I. -I$(LIBFT_DIR) -I$(LIBMLX_DIR)

# GLFW path for macOS(comment out when on Linux)
GLFW_PATH = /opt/homebrew/opt/glfw

LIBMLX_DIR = ./lib/MLX42
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a 

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Linux
#LIBS = $(LIBFT) $(LIBMLX) -ldl -lm -lglfw -lGL
# MacOS
LIBS = $(LIBFT) $(LIBMLX) -L$(GLFW_PATH)/lib -ldl -lm -lglfw -framework OpenGL

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

# Compilation rule for .c to .o
.c.o:
	@echo "Compiling $<..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

# Linking and building the executable
$(NAME):	$(OBJ)	$(LIBFT)	$(LIBMLX)
			@echo "Linking stuff..."
			@$(CC)	$(CFLAGS)	$(OBJ)	$(LIBS)	-o	$(NAME)
			@echo "$(NAME) created successfully!"

# Build libft library
$(LIBFT):
		@echo "Building libft..."
		@$(MAKE)	-C	$(LIBFT_DIR)

# Build libmlx library
$(LIBMLX):
	@mkdir -p $(LIBMLX_DIR)/build
	@cd $(LIBMLX_DIR)/build && cmake .. && make

# Default target
all	: libft libmlx	$(NAME)

# Clean object files
clean:
	@echo "Cleaning object files..."
	@$(RM)	$(OBJ)
	@$(MAKE)	-C	$(LIBFT_DIR) clean
	@$(MAKE)	-C $(LIBMLX_DIR)/build clean

# Full clean including libraries
fclean:
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(LIBMLX_DIR)/build

# Rebuild
re: fclean all

.PHONY: all libft libmlx clean fclean re
