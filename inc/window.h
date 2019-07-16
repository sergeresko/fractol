/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:36:00 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 15:41:04 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "fractol.h"		// t_win

// const?
void	window_display(t_win *window);
void	window_display_with_shifted_help(t_win *window, int shift_x, int shift_y);
void	window_display_with_shifted_status(t_win *window, int shift_x, int shift_y);
void	window_redraw(t_win *window);		// window_update

#endif
