/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:08:10 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/14 17:46:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MENU_WIDTH		190
#define MENU_HEIGHT		440

// #define COLOR_BACKGROUND	0x40808080
// #define COLOR_BORDER		0x00ffffff

#define COLOR_TITLE		0x000000
#define COLOR_CONTROL	0xee5555
#define COLOR_TEXT		0xffffff

#define LINE_HEIGHT		20

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

static void		menu_display_mouse_controls(t_win *window, int x)
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

	menu_display_lines(window, x, 20, lines);
}

static void		menu_display_keyboard_controls(t_win *window, int x)
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
		"I     ", "       info",
		"ESC   ", "       close",
		NULL,
	};

	menu_display_lines(window, x, 160, lines);
}

static void		menu_display_shift_control(t_win *window, int x)
{
	static char	*lines[] = {
		"SHIFT", "      + anything",
		"", "apply the action",
		"", "to all windows",
		NULL,
	};

	menu_display_lines(window, x, 380, lines);
}

void			menu_display(t_win *window, int offset)
{
	int const	x = 20 + offset;		// TODO:
	static void	*background = NULL;

	if (!background)
	{
		background = background_create(window->program->mlx_ptr, MENU_WIDTH, MENU_HEIGHT);
	}
	background_display(window, background, 10, 10);		// TODO: offset
	menu_display_mouse_controls(window, x);
	menu_display_keyboard_controls(window, x);
	menu_display_shift_control(window, x);
}
