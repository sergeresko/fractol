/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:36:11 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:09:22 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# include "fractol.h"
# include <mlx.h>

# define COLOR_TITLE		0xee9900
# define COLOR_CONTROL		0xeedd00
# define COLOR_TEXT			0xeeeeee
# define COLOR_BACKGROUND	0x40808080
# define COLOR_BORDER		COLOR_TEXT

# define OFFSET_X			10
# define OFFSET_Y			5

# define LINE_HEIGHT		20

# define BOX_WIDTH			190

void	*background_create(void *mlx_ptr, int width, int height);
void	background_display(t_win *window, void *background, int x, int y);

void	help_display(t_win *window, int x, int y);
void	status_display(t_win *window, int x, int y);

void	image_recompute(t_win *window);
void	image_display(t_win *window);

#endif
