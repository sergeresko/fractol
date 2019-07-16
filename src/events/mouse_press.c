/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:30 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 21:10:07 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"

int		mouse_press(int button, int x, int y, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;

	if (button == MOUSE_BUTTON_LEFT && !(program->drag_mode))
	{
		program->drag_mode = 1;
		program->drag_x = x;
		program->drag_y = y;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		apply(action_zoom_out, window, x, y);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		apply(action_zoom_in, window, x, y);
	}
	else if (button == MOUSE_SCROLL_LEFT)
	{
		apply(action_change_iterations, window, +1, UNUSED);
	}
	else if (button == MOUSE_SCROLL_RIGHT)
	{
		apply(action_change_iterations, window, -1, UNUSED);
	}
	return (0);
}
