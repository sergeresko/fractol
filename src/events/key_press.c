/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 17:39:22 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "actions.h"

// TODO: static


typedef struct	s_todo
{
	int		key;
	t_func	action;
	int		a;
	int		b;
}				t_todo;

static t_todo const	*find(int key, t_todo const *todos, int size)
{
	while (size--)
	{
		if (todos[size].key == key)
		{
			return (&(todos[size]));
		}
	}
	return (NULL);
}

static t_todo const	*get_action_by_key(int key)		// TODO: rename
{
	static t_todo const	todos[] = {
		{KEY_ARROW_UP, action_move, 0, +STEP_ARROW_MOVE},
		{KEY_ARROW_DOWN, action_move, 0, -STEP_ARROW_MOVE},
		{KEY_ARROW_LEFT, action_move, +STEP_ARROW_MOVE, 0},
		{KEY_ARROW_RIGHT, action_move, -STEP_ARROW_MOVE, 0},
		{KEY_MINUS, action_zoom_out, -1, -1},			// TODO: define
		{KEY_EQUALS, action_zoom_in, -1, -1},			// TODO: define
		{KEY_BRACKET_LEFT, action_change_iterations, -1, UNUSED},
		{KEY_BRACKET_RIGHT, action_change_iterations, +1, UNUSED},
		{KEY_ZERO, action_reset, UNUSED, UNUSED},
		{KEY_ONE, action_set_palette, 1, UNUSED},
		{KEY_TWO, action_set_palette, 2, UNUSED},
		// ...
	};

	return (find(key, todos, sizeof(todos) / sizeof(*todos)));
}

static t_todo const *get_action_by_key_numpad(int key)
{
	static t_todo const	todos[] = {
		{KEY_MINUS_NUMPAD, action_zoom_out, -1, -1},	// TODO: define
		{KEY_PLUS_NUMPAD, action_zoom_in, -1, -1},		// TODO: define
		{KEY_ZERO_NUMPAD, action_reset, UNUSED, UNUSED},
		{KEY_ONE_NUMPAD, action_set_palette, 1, UNUSED},
		{KEY_TWO_NUMPAD, action_set_palette, 2, UNUSED},
		// ...
	};

	return (find(key, todos, sizeof(todos) / sizeof(*todos)));
}

//

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

static int		other(int key, t_win *window)
{
	/*
	static t_z const	zs[] = {
		{KEY_SPACE, toggle_fixed},
		{KEY_H, toggle_help},
		{KEY_S, toggle_status},
	};
	int					i;

	i = sizeof(zs) / sizeof(*zs);
	while (i--)
	{
		if (key == zs[i].key)
		{
			zs[i].func(window);
			return (1);
		}
	}
	return (0);
	*/
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

/*
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
*/

int		key_press(int key, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;	// unneeded?
	t_todo const	*todo;

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
	else if (!other(key, window))
	{
		if ((todo = get_action_by_key(key))
				|| (todo = get_action_by_key_numpad(key)))
		{
			apply(todo->action, window, todo->a, todo->b);
		}
	}
	return (0);
}

/*
{
	t_todo const	*todo;

	if ((todo = get_action_by_key(key))
			|| (todo = get_action_by_key_numpad(key)))
	{
		apply(todo->action, window, todo->a, todo->b);
	}
	else if (key == KEY_ESCAPE)
	{
		win_close(window);
	}
	else if (key == KEY_SHIFT_LEFT)
	{
		((t_win *)window)->program->global_mode |= LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		((t_win *)window)->program->global_mode |= RIGHT_SHIFT_PRESSED;
	}
	else
	{
		other(key, window);
	}
	return (0);
}
*/
