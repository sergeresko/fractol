/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:08:10 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/14 14:39:49 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//#include <mlx.h>		// or "mlx.h" ?

#define COLOR_TITLE		0x000000
#define COLOR_CONTROL	0xee5555
#define COLOR_TEXT		0xffffff

#define LINE_HEIGHT		20

static void		menu_display_lines(t_win *window, int x, int y, char **lines)
{
	void *const		mlx_ptr = window->program->mlx_ptr;
	void *const		win_ptr = window->win_ptr;

	while (*lines)
	{
		mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_CONTROL, *(lines++));
		mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TEXT, *(lines++));
		y += LINE_HEIGHT;
	}
}

static void		menu_display_mouse_controls(t_win *window, int x)
{
	static char		*lines[] = {
		"drag        ", "       move image",
		"scroll      ", "      :",
		"  vertical  ", "             zoom",
		"  horizontal", "             iter",
		"move        ", "       vary param",
		NULL,
	};

	menu_display_lines(window, x, 40, lines);
	// TODO:
}

static void		menu_display_keyboard_controls(t_win *window, int x)
{
	static char		*lines[] = {
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

	menu_display_lines(window, x, 180, lines);
	// TODO:
}

static void		menu_display_shift_control(t_win *window, int x)
{
	void *const		mlx_ptr = window->program->mlx_ptr;
	void *const		win_ptr = window->win_ptr;
	int				y;

	// TODO:
	y = 380;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_CONTROL, "SHIFT");
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TITLE, "      + anything");
	y += LINE_HEIGHT;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TEXT, "apply the action");
	y += LINE_HEIGHT;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_TEXT, "to all windows");
}

// background

void		display_background(t_win *window)
{
	void *const		img_ptr = mlx_new_image(window->program->mlx_ptr, 190, 440);
	int				tmp;
	int *const		data = (int *)mlx_get_data_addr(img_ptr, &tmp, &tmp, &tmp);
	int				i;

	i = 190 * 440;
	while (i--)
	{
		data[i] = 0x40808080;
	}
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr, img_ptr, 10, 10);
	mlx_destroy_image(window->program->mlx_ptr, img_ptr);
}

void		menu_display(t_win *window, int offset)
{
	void *const		mlx_ptr = window->program->mlx_ptr;
	void *const		win_ptr = window->win_ptr;
	int const		x = 20 + offset;

	display_background(window);
	// TODO: background
	mlx_string_put(mlx_ptr, win_ptr, x, 20, COLOR_TITLE, "Keyboard controls");
	menu_display_mouse_controls(window, x);

	mlx_string_put(mlx_ptr, win_ptr, x, 160, COLOR_TITLE, "Mouse controls");
	menu_display_keyboard_controls(window, x);

	menu_display_shift_control(window, x);
	// TODO:
}
