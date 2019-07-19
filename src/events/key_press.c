/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 15:28:48 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"
#include "events.h"		// win_close

#define MOVE_STEP	32

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

static t_bind const	*get_binding_by_key(int key)
{
	static t_bind const	bindings[] = {
		{KEY_ARROW_UP, action_move, 0, +MOVE_STEP},
		{KEY_ARROW_DOWN, action_move, 0, -MOVE_STEP},
		{KEY_ARROW_LEFT, action_move, +MOVE_STEP, 0},
		{KEY_ARROW_RIGHT, action_move, -MOVE_STEP, 0},
		{KEY_MINUS, action_zoom_out, ZOOM_CENTER, ZOOM_CENTER},
		{KEY_EQUALS, action_zoom_in, ZOOM_CENTER, ZOOM_CENTER},
		{KEY_BRACKET_LEFT, action_change_iterations, ITER_DECREASE, UNUSED},
		{KEY_BRACKET_RIGHT, action_change_iterations, ITER_INCREASE, UNUSED},
		{KEY_0, action_reset, UNUSED, UNUSED},
		{KEY_1, action_set_palette, 1, UNUSED},
		{KEY_2, action_set_palette, 2, UNUSED},
		{KEY_3, action_set_palette, 3, UNUSED},
		{KEY_4, action_set_palette, 4, UNUSED},
		{KEY_5, action_set_palette, 5, UNUSED},
		{KEY_6, action_set_palette, 6, UNUSED},
		{KEY_7, action_set_palette, 7, UNUSED},
		{KEY_8, action_set_palette, 8, UNUSED},
		{KEY_9, action_set_palette, 9, UNUSED},
	};

	return (find(key, bindings, sizeof(bindings) / sizeof(*bindings)));
}

static t_bind const *get_binding_by_key_numpad(int key)
{
	static t_bind const	bindings[] = {
		{KEY_MINUS_NUMPAD, action_zoom_out, ZOOM_CENTER, ZOOM_CENTER},
		{KEY_PLUS_NUMPAD, action_zoom_in, ZOOM_CENTER, ZOOM_CENTER},
		{KEY_0_NUMPAD, action_reset, UNUSED, UNUSED},
		{KEY_1_NUMPAD, action_set_palette, 1, UNUSED},
		{KEY_2_NUMPAD, action_set_palette, 2, UNUSED},
		{KEY_3_NUMPAD, action_set_palette, 3, UNUSED},
		{KEY_4_NUMPAD, action_set_palette, 4, UNUSED},
		{KEY_5_NUMPAD, action_set_palette, 5, UNUSED},
		{KEY_6_NUMPAD, action_set_palette, 6, UNUSED},
		{KEY_7_NUMPAD, action_set_palette, 7, UNUSED},
		{KEY_8_NUMPAD, action_set_palette, 8, UNUSED},
		{KEY_9_NUMPAD, action_set_palette, 9, UNUSED},
	};

	return (find(key, bindings, sizeof(bindings) / sizeof(*bindings)));
}

int					key_press(int key, void *window)
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
