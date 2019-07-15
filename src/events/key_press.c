/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 15:52:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "actions.h"

// TODO: static

/*
static t_todo const	*find(int key, t_todo const *todo, int size)
{
	while (size--)
	{
		if (todo[size].key == key)
		{
			return (&(todo[size]));
		}
	}
	return (NULL);
}

static t_todo const	*search(int key)
{
	static t_todo const	todo[] = {
		{KEY_ARROW_UP, action_move, 0, +STEP_ARROW_MOVE},
		{KEY_ARROW_DOWN, action_move, 0, -STEP_ARROW_MOVE},
		{KEY_ARROW_LEFT, action_move, +STEP_ARROW_MOVE, 0},
		{KEY_ARROW_RIGHT, action_move, -STEP_ARROW_MOVE, 0},
		{KEY_MINUS, action_zoom_out, -1, -1},			// TODO: define
		{KEY_MINUS_NUMPAD, action_zoom_out, -1, -1},	// TODO: define
		{KEY_EQUALS, action_zoom_in, -1, -1},			// TODO: define
		{KEY_PLUS_NUMPAD, action_zoom_in, -1, -1},		// TODO: define
		{KEY_BRACKET_LEFT, action_change_iterations, -1, UNUSED},
		{KEY_BRACKET_RIGHT, action_change_iterations, +1, UNUSED},
		// ...
		{KEY_ZERO, action_reset, UNUSED, UNUSED},
		{KEY_ZERO_NUMPAD, action_reset, UNUSED, UNUSED},
		//
		{KEY_ONE, action_set_palette, 1, UNUSED},
		{KEY_ONE_NUMPAD, action_set_palette, 1, UNUSED},
		{KEY_TWO, action_set_palette, 2, UNUSED},
		{KEY_TWO_NUMPAD, action_set_palette, 2, UNUSED},
		// ...
	};

	return (find(key, todo, sizeof(todo) / sizeof(*todo)));
}
*/

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

int		key_press_reset(int key, t_win *window)
{
	if (key == KEY_ZERO || key == KEY_ZERO_NUMPAD)
	{
		apply(action_reset, window, UNUSED, UNUSED);
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

void	toggle_help(t_win *window)
{
	int const	is_help_shown = window->is_menu_shown;
	int			frame;

	frame = 0;
	while (++frame < 8)
	{
		mlx_do_sync(window->program->mlx_ptr);
		apply(action_shift_help, window, is_help_shown, frame);
	}
	apply(action_toggle_help, window, is_help_shown, UNUSED);
}

void	toggle_status(t_win *window)
{
	int const	is_status_shown = window->is_info_shown;
	int			frame;

	frame = 0;
	while (++frame < 5)
	{
		mlx_do_sync(window->program->mlx_ptr);
		apply(action_shift_status, window, is_status_shown, frame);
	}
	apply(action_toggle_status, window, is_status_shown, UNUSED);
}

int		key_press_toggle(int key, t_win *window)
{
	if (key == KEY_SPACE)
	{
		apply(action_toggle_fix, window, window->is_fixed, UNUSED);
	}
	else if (key == KEY_H)
	{
		toggle_help(window);
	}
	else if (key == KEY_S)
	{
		toggle_status(window);
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press_iterations(int key, t_win *window)
{
	if (key == KEY_BRACKET_LEFT)
	{
		apply(action_change_iterations, window, -1, UNUSED);
	}
	else if (key == KEY_BRACKET_RIGHT)
	{
		apply(action_change_iterations, window, +1, UNUSED);
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
				|| key_press_zoom(key, window) || key_press_reset(key, window)
				|| key_press_toggle(key, window) || key_press_iterations(key, window);
		// ...
	}
	return (0);
}
