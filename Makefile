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

NAME		=	fractol
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Wpedantic

# --------- Header files ------------------------------------------------------

INC			=	$(addprefix inc/,					\
					fractol.h						\
				)

# --------- Source files ------------------------------------------------------

SRC			=	$(addprefix src/,					\
					get.c							\
					opt.c							\
					process_global_options.c		\
					process_arguments.c				\
					is_subseq.c						\
					atoi_positive.c					\
					get_opt_by_character.c			\
					set_option.c					\
					error.c							\
					sprintf_int.c					\
					print_usage.c					\
				)

# --------- Object files ------------------------------------------------------

OBJ			=	$(patsubst src/%.c, obj/%.o, $(SRC))

# --------- Phony targets -----------------------------------------------------

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@ rm -f $(OBJ)
	@ make clean -sC libft/

fclean: clean
	@ rm -rf obj/
	@ rm -f $(NAME)
	@ make fclean -sC libft/

re: fclean all

# --------- Linking -----------------------------------------------------------

$(NAME): $(LIBFT) $(OBJ)
	@ mkdir -p obj/
	@ printf "%-60s\n" "Linking $@"
	@ $(CC) $(OBJ) $(LIBFT) -o $@
	@ echo "Done"

$(LIBFT):
	@ echo "Building $@"
	@ make -sC libft/
	@ echo "Done"

# --------- Compiling ---------------------------------------------------------

obj/%.o: src/%.c $(INC) libft/libft.h
	@ mkdir -p $(dir $@)
	@ printf "%-60s\r" "Compiling $<"
	@ $(CC) $(CFLAGS) -c $< -Iinc/ -Ilibft/ -o $@

# TODO:
#FRAMEWORKS	=	-framework OpenGL -framework AppKit
#LIBRARIES	+=	-lmlx
LIBRARIES	+=	libft/libft.a
