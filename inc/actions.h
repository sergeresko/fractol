/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:19:42 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 18:11:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "fractol.h"

/*
**	actions
*/

void	action_move(t_win *window, int shift_x, int shift_y);

void	action_zoom_out(t_win *window, int x, int y);
void	action_zoom_in(t_win *window, int x, int y);

void	action_change_iterations(t_win *window, int direction, int unused);

void	action_update_variable(t_win *window, int unused_1, int unused_2);

void	action_reset(t_win *window, int unused_1, int unused_2);

void	action_set_palette(t_win *window, int color_scheme, int unused);

void	action_animate_help(t_win *window, int is_help_shown, int frame);
void	action_animate_status(t_win *window, int is_status_shown, int frame);

void	action_toggle_fix(t_win *window, int is_fixed, int unused);
void	action_toggle_help(t_win *window, int is_help_shown, int unused);
void	action_toggle_status(t_win *window, int is_status_shown, int unused);

void	action_close(t_win *window, int unused_1, int unused_2);

/*
**	generic action application
*/

typedef void	(*t_act)(t_win *, int, int);

void	apply(t_act action, t_win *window, int a, int b);

#endif
