/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:30 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 13:25:32 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "actions.h"

int		mouse_press(int button, int x, int y, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;

	if (button == MOUSE_BUTTON_LEFT)
	{
		if (!(program->drag_mode))
		{
			program->drag_x = x;
			program->drag_y = y;
		}
		program->drag_mode = 1;		// move into the if body above ? then may write `if (button == ... && !(...))`
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		apply(action_zoom_out, window, x, y);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		apply(action_zoom_in, window, x, y);
	}
	// TODO: else ... (horizontal scroll - iterations)
	return (0);
}
