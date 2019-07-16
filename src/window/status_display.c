/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:52:59 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:40:44 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"
#include "libft.h"		// ft_strcpy

#define COLOR_TEXT		0xffffff		// TODO: make common with help

#define LINE_HEIGHT		20

#define OFFSET_X			10
#define OFFSET_Y			5

#define STATUS_WIDTH		190
#define STATUS_HEIGHT		(OFFSET_Y + LINE_HEIGHT + 8)

static void	status_display_iterations(t_win *window, int x, int y)
{
	char	status[17];

	sprintf_int_right(window->param.iteration_max, status, 4);
	if (window->is_fixed)
	{
		ft_strcpy(status + 4, "   fixed");
	}
	else
	{
		status[4] = '\0';
	}
	mlx_string_put(window->program->mlx_ptr, window->win_ptr,
			x + OFFSET_X, y + OFFSET_Y, COLOR_TEXT, status);	// TODO:
}

void		status_display(t_win *window, int x, int y)
{
	static void	*background = NULL;

	if (!background)
	{
		background = background_create(window->program->mlx_ptr,
				STATUS_WIDTH, STATUS_HEIGHT);
	}
	background_display(window, background, x, y);
	status_display_iterations(window, x, y);
}
