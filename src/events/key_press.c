/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 13:25:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "actions.h"

// TODO: static

int		key_press_arrow(int key, t_win *window)
{
//	int		shift_x;
//	int		shift_y;

	if (key == KEY_ARROW_UP)
	{
		apply(action_move, window, 0, +STEP_ARROW_MOVE);
	}
	else if (key == KEY_ARROW_DOWN)
	{
		apply(action_move, window, 0, -STEP_ARROW_MOVE);
	}
	else if (key == KEY_ARROW_LEFT)
	{
		apply(action_move, window, +STEP_ARROW_MOVE, 0);
	}
	else if (key == KEY_ARROW_RIGHT)
	{
		apply(action_move, window, -STEP_ARROW_MOVE, 0);
	}
	else
	{
		return 0;		// fail
	}
	return 1;			// success
}

int		key_press_digit(int key, t_win *window)
{
	if (key == KEY_ONE || key == KEY_ONE_NUMPAD)
	{
		apply(action_set_palette, window, 1, UNUSED);
	}
	else if (key == KEY_TWO || key == KEY_TWO_NUMPAD)
	{
		apply(action_set_palette, window, 2, UNUSED);
	}
	// TODO:
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press_zoom(int key, t_win *window)
{
	if (key == KEY_MINUS || key == KEY_MINUS_NUMPAD)
	{
		apply(action_zoom_out, window, -1, -1);		// TODO: define
	}
	else if (key == KEY_EQUALS || key == KEY_PLUS_NUMPAD)
	{
		apply(action_zoom_in, window, -1, -1);		// TODO: define
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press_space(int key, t_win *window)
{
	if (key == KEY_SPACE)
	{
		apply(action_reset, window, UNUSED, UNUSED);
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press(int key, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;	// unneeded?

	if (key == KEY_ESCAPE)
	{
		win_close(window);
	}
	else if (key == KEY_SHIFT_LEFT)
	{
		program->global_mode |= LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		program->global_mode |= RIGHT_SHIFT_PRESSED;
	}
	else
	{
		key_press_arrow(key, window) || key_press_digit(key, window)
				|| key_press_zoom(key, window) || key_press_space(key, window);
		// ...
	}
	return (0);
}
