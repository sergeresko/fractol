# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 18:37:27 by syeresko          #+#    #+#              #
#    Updated: 2019/07/19 18:10:40 by syeresko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Wpedantic -Werror -DCL_SILENCE_DEPRECATION

# --------- Header files ------------------------------------------------------

INC			=	$(addprefix inc/,					\
					fractol.h						\
					palettes.h						\
					actions.h						\
					events.h						\
					events_private.h				\
					window.h						\
					window_private.h				\
				)

# --------- Source files ------------------------------------------------------

SRC			=	$(addprefix src/,					\
					main.c							\
					process_global_options.c		\
					process_arguments.c				\
					parse_argument.c				\
					set_option.c					\
					info.c							\
					error.c							\
					sprintf_int.c					\
					print_usage.c					\
					start_mlx.c						\
					start_opencl.c					\
					$(addprefix palettes/,			\
						palette_periodic.c			\
						palette_other.c				\
						fill_palette.c				\
					)								\
					$(addprefix actions/,			\
						action_move.c				\
						action_zoom.c				\
						action_change_iterations.c	\
						action_update_variable.c	\
						action_reset.c				\
						action_set_palette.c		\
						action_animate.c			\
						action_toggle.c				\
						action_close.c				\
						apply.c						\
					)								\
					$(addprefix window/,			\
						background.c				\
						help_display.c				\
						status_display.c			\
						window.c					\
					)								\
					$(addprefix events/,			\
						key_press.c					\
						key_press_toggle.c			\
						key_release.c				\
						mouse_move.c				\
						mouse_press.c				\
						mouse_release.c				\
						win_close.c					\
					)								\
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

# TODO:
FRAMEWORKS	+=	-framework OpenCL
FRAMEWORKS	+=	-framework OpenGL -framework AppKit
LIBRARIES	+=	-lmlx
LIBRARIES	+=	$(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
	@ mkdir -p obj/
	@ printf "%-60s\n" "Linking $@"
	@ $(CC) $(CFLAGS) $(OBJ) $(FRAMEWORKS) $(LIBRARIES) -o $@
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
