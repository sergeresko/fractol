/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 18:17:27 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
//#include "keycodes.h"
//#include "actions.h"
#include "events.h"

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

int		key_press(int key, void *window)
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
	else
	{
		key_press_toggle(key, window);
	}
	return (0);
}
