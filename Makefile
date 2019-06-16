# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 18:37:27 by syeresko          #+#    #+#              #
#    Updated: 2019/06/16 19:04:59 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	get.c \
			get_opt.c \
			process_global_options.c \
			is_subseq.c \
			str_to_positive_int.c \
			get_opt_by_character.c \
			set_global_option.c \
			die.c

FRAMEWORKS	=	-framework OpenGL -framework AppKit
INCLUDES	=	-I. -I/Users/syeresko/projects/filler/rendu/libft
LIBRARIES	=	-lmlx ~/projects/filler/my/libft_gnl_printf/libft.a

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ $(FRAMEWORKS) $(INCLUDES) $(LIBRARIES) -o $@
