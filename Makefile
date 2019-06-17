# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 18:37:27 by syeresko          #+#    #+#              #
#    Updated: 2019/06/17 19:58:23 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	get.c \
			opt.c \
			process_global_options.c \
			process_arguments.c \
			is_subseq.c \
			atoi.c \
			get_opt_by_character.c \
			set_option.c \
			error.c \
			print_usage.c

FRAMEWORKS	=	-framework OpenGL -framework AppKit
INCLUDES	=	-I. -Ilibft
LIBRARIES	=	-lmlx libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ $(FRAMEWORKS) $(INCLUDES) $(LIBRARIES) -o $@
