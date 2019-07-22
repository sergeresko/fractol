/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:36:00 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:03:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "fractol.h"

# define HELP_FRAME_COUNT		8
# define HELP_ANIMATION_STEP	25
# define STATUS_FRAME_COUNT		5
# define STATUS_ANIMATION_STEP	8

void	window_display(t_win *window);
void	window_display_shift_help(t_win *window, int shift_x, int shift_y);
void	window_display_shift_status(t_win *window, int shift_x, int shift_y);
void	window_update(t_win *window);

#endif
