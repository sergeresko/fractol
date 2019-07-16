/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:19:42 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 15:35:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "fractol.h"		// t_win

# define STEP_ARROW_MOVE		32		// where?
# define STEP_ZOOM				0.1		// where?

# define UNUSED				0

// maybe the following two constants should be defined elsewhere
# define LEFT_SHIFT_PRESSED		(1 << 0)
# define RIGHT_SHIFT_PRESSED	(1 << 1)

typedef void	(*t_act)(t_win *, int, int);		// or in events_private.h

void	apply(t_act action, t_win *window, int a, int b);	// or in events_private.h

void	action_move(t_win *window, int shift_x, int shift_y);
void	action_set_palette(t_win *window, int color_scheme, int unused);
void	action_close(t_win *window, int unused_1, int unused_2);
void	action_zoom_out(t_win *window, int x, int y);
void	action_zoom_in(t_win *window, int x, int y);
void	action_reset(t_win *window, int unused_1, int unused_2);
void	action_update_julia(t_win *window, int unused_1, int unused_2);
void	action_toggle_fix(t_win *window, int is_fixed, int unused);
void	action_change_iterations(t_win *window, int direction, int unused);

void	action_shift_help(t_win *window, int is_help_shown, int frame);
void	action_toggle_help(t_win *window, int is_help_shown, int unused);
void	action_shift_status(t_win *window, int is_status_shown, int frame);
void	action_toggle_status(t_win *window, int is_status_shown, int unused);

#endif
