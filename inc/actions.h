/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:19:42 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 16:33:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "fractol.h"

# define STEP_ARROW_MOVE		32
# define STEP_ZOOM				0.1

# define UNUSED				0

// maybe the following two constants should be defined elsewhere
# define LEFT_SHIFT_PRESSED		(1 << 0)
# define RIGHT_SHIFT_PRESSED	(1 << 1)

typedef void	(*t_func)(t_win *, int, int);

void		apply(t_func action, t_win *window, int a, int b);

void	action_move(t_win *window, int shift_x, int shift_y);
void	action_set_palette(t_win *window, int color_scheme, int unused);
void	action_close(t_win *window, int unused_1, int unused_2);
void	action_zoom_out(t_win *window, int x, int y);
void	action_zoom_in(t_win *window, int x, int y);
void	action_reset(t_win *window, int unused_1, int unused_2);
void	action_update_julia(t_win *window, int unused_1, int unused_2);

#endif
