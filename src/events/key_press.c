/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:04:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
//#include "keycodes.h"
//#include "actions.h"
#include "events_private.h"
#include "events.h"		// win_close

static t_bind const	*find(int key, t_bind const *bindings, int size)
{
	while (size--)
	{
		if (bindings[size].key == key)
		{
			return (&(bindings[size]));
		}
	}
	return (NULL);
}

static t_bind const	*get_binding_by_key(int key)		// TODO: rename
{
	static t_bind const	bindings[] = {
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
		{KEY_THREE, action_set_palette, 3, UNUSED},
		{KEY_FOUR, action_set_palette, 4, UNUSED},
		// ...
	};

	return (find(key, bindings, sizeof(bindings) / sizeof(*bindings)));
}

static t_bind const *get_binding_by_key_numpad(int key)
{
	static t_bind const	bindings[] = {
		{KEY_MINUS_NUMPAD, action_zoom_out, -1, -1},	// TODO: define
		{KEY_PLUS_NUMPAD, action_zoom_in, -1, -1},		// TODO: define
		{KEY_ZERO_NUMPAD, action_reset, UNUSED, UNUSED},
		{KEY_ONE_NUMPAD, action_set_palette, 1, UNUSED},
		{KEY_TWO_NUMPAD, action_set_palette, 2, UNUSED},
		{KEY_THREE_NUMPAD, action_set_palette, 3, UNUSED},
		{KEY_FOUR_NUMPAD, action_set_palette, 4, UNUSED},
		// ...
	};

	return (find(key, bindings, sizeof(bindings) / sizeof(*bindings)));
}

int		key_press(int key, void *window)
{
	t_bind const	*binding;

	if ((binding = get_binding_by_key(key))
			|| (binding = get_binding_by_key_numpad(key)))
	{
		apply(binding->action, window, binding->a, binding->b);
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
