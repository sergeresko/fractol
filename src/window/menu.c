/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:08:10 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 15:54:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define COLOR_TITLE		0x000000
#define COLOR_CONTROL	0xee5555
#define COLOR_TEXT		0xffffff

#define LINE_HEIGHT		20

#define OFFSET_X			10
#define OFFSET_Y_MOUSE		5
#define OFFSET_Y_KEYBOARD	(OFFSET_Y_MOUSE + 7 * LINE_HEIGHT)
#define OFFSET_Y_SHIFT		(OFFSET_Y_KEYBOARD + 11 * LINE_HEIGHT)

#define MENU_WIDTH		190
#define MENU_HEIGHT		(OFFSET_Y_SHIFT + 3 * LINE_HEIGHT + 8)

static void		menu_display_lines(t_win *window, int x, int y, char **lines)
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

static void		menu_display_mouse_controls(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"", "Mouse controls",
		"drag        ", "       move image",
		"scroll      ", "      :",
		"  vertical  ", "             zoom",
		"  horizontal", "             iter",
		"move        ", "       vary param",
		NULL,
	};

	menu_display_lines(window, x + OFFSET_X, y + OFFSET_Y_MOUSE, lines);
}

static void		menu_display_keyboard_controls(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"", "Keyboard controls",
		"arrows", "       move image",
		"- +   ", "       zoom",
		"[ ]   ", "       iterations",
		"SPACE ", "       fix param",
		"0     ", "       reset",
		"1   5 ", " ...   palette",
		"H     ", "       help",
		"S     ", "       status bar",
		"ESC   ", "       close",
		NULL,
	};

	menu_display_lines(window, x + OFFSET_X, y + OFFSET_Y_KEYBOARD, lines);
}

static void		menu_display_shift_control(t_win *window, int x, int y)
{
	static char	*lines[] = {
		"SHIFT", "      + anything",
		"", "apply the action",
		"", "to all windows",
		NULL,
	};

	menu_display_lines(window, x + OFFSET_X, y + OFFSET_Y_SHIFT, lines);
}

void			menu_display(t_win *window, int x, int y)
{
	static void	*background = NULL;

	if (!background)
	{
		background = background_create(window->program->mlx_ptr,
				MENU_WIDTH, MENU_HEIGHT);
	}
	background_display(window, background, x, y);
	menu_display_mouse_controls(window, x, y);
	menu_display_keyboard_controls(window, x, y);
	menu_display_shift_control(window, x, y);
}
