/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_toggle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:10:07 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 17:32:01 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"
#include "window.h"
#include <time.h>

#define FRAME_DURATION		32		// TODO: choose a reasonable value

static void	toggle_help(t_win *window)
{
	int const		is_help_shown = window->is_help_shown;
	clock_t const	start = clock();
	int				frame;

	frame = 0;
	while (++frame < HELP_FRAME_COUNT)
	{
		while (clock() - start < FRAME_DURATION * frame)
			;
		apply(action_animate_help, window, is_help_shown, frame);
	}
	apply(action_toggle_help, window, is_help_shown, UNUSED);
}

static void	toggle_status(t_win *window)
{
	int const		is_status_shown = window->is_status_shown;
	clock_t const	start = clock();
	int				frame;

	frame = 0;
	while (++frame < STATUS_FRAME_COUNT)
	{
		while (clock() - start < FRAME_DURATION * frame)
			;
		apply(action_animate_status, window, is_status_shown, frame);
	}
	apply(action_toggle_status, window, is_status_shown, UNUSED);
}

void		key_press_toggle(int key, t_win *window)
{
	if (key == KEY_SHIFT_LEFT)
	{
		window->program->global_mode |= LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		window->program->global_mode |= RIGHT_SHIFT_PRESSED;
	}
	else if (key == KEY_SPACE)
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
}
