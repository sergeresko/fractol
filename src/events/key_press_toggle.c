/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_toggle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:10:07 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 18:16:33 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
//#include "keycodes.h"
//#include "actions.h"
#include "events.h"

static void		toggle_help(t_win *window)
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

static void		toggle_status(t_win *window)
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

void			key_press_toggle(int key, t_win *window)
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
