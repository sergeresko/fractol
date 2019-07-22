/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:52:59 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/18 21:38:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"
#include "libft.h"		// ft_strcpy

#define STATUS_WIDTH		BOX_WIDTH
#define STATUS_HEIGHT		(OFFSET_Y + LINE_HEIGHT + 8)

static void	status_display_iterations(t_win *window, int x, int y)
{
	char	status[17];

	sprintf_int_right(window->param.iteration_max, status, 4);
	ft_strcpy(status + 4, window->is_fixed ? "   fixed" : "");
	mlx_string_put(window->program->mlx_ptr, window->win_ptr,
			x + OFFSET_X, y + OFFSET_Y, COLOR_TEXT, status);
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
