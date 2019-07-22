/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:08:10 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/18 21:38:02 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

#define OFFSET_Y_MOUSE		OFFSET_Y
#define OFFSET_Y_KEYBOARD	(OFFSET_Y_MOUSE + 7 * LINE_HEIGHT)
#define OFFSET_Y_SHIFT		(OFFSET_Y_KEYBOARD + 11 * LINE_HEIGHT)

#define HELP_WIDTH			BOX_WIDTH
#define HELP_HEIGHT			(OFFSET_Y_SHIFT + 3 * LINE_HEIGHT + 8)

static void	help_display_lines(t_win *window, int x, int y, char **lines)
{
	void *const	mlx_ptr = window->program->mlx_ptr;
	void *const	win_ptr = window->win_ptr;

	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_CONTROL, *(lines++));
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TITLE, *(lines++));
	while (*lines)
	{
		y += LINE_HEIGHT;
		mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_CONTROL, *(lines++));
		mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TEXT, *(lines++));
	}
}

static void	help_display_mouse_controls(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"", "Mouse controls",
		"drag        ", "       move image",
		"scroll      ", "      :",
		"  up down   ", "    /        zoom",
		"  left right", "      /      iter",
		"move        ", "       vary param",
		NULL,
	};

	help_display_lines(window, x + OFFSET_X, y + OFFSET_Y_MOUSE, lines);
}

static void	help_display_keyboard_controls(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"", "Keyboard controls",
		"arrows", "       move image",
		"- +   ", "       zoom",
		"[ ]   ", "       iterations",
		"SPACE ", "       fix param",
		"0     ", "       reset",
		"1   9 ", " ...   palette",
		"H     ", "       help",
		"S     ", "       status bar",
		"ESC   ", "       close",
		NULL,
	};

	help_display_lines(window, x + OFFSET_X, y + OFFSET_Y_KEYBOARD, lines);
}

static void	help_display_shift_control(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"SHIFT", "      + anything",
		"", "apply the action",
		"", "to all windows",
		NULL,
	};

	help_display_lines(window, x + OFFSET_X, y + OFFSET_Y_SHIFT, lines);
}

void		help_display(t_win *window, int x, int y)
{
	static void	*background = NULL;

	if (!background)
	{
		background = background_create(window->program->mlx_ptr,
				HELP_WIDTH, HELP_HEIGHT);
	}
	background_display(window, background, x, y);
	help_display_mouse_controls(window, x, y);
	help_display_keyboard_controls(window, x, y);
	help_display_shift_control(window, x, y);
}
