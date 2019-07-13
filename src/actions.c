#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

#include "actions.h"

/*
#define LEFT_SHIFT_PRESSED	(1 << 0)
#define RIGHT_SHIFT_PRESSED	(1 << 1)

#define STEP_ARROW_MOVE		32
#define STEP_ZOOM			0.1

#define UNUSED				0

typedef void	(*t_func)(t_win *, int, int);
*/

void		apply(t_func action, t_win *window, int a, int b)
{
	t_prog *const	program = window->program;
	int				window_index;

	if (program->global_mode)
	{
		window_index = program->window_count;
		while (window_index--)
		{
			window = &(program->windows[window_index]);
			if (window->is_alive)
			{
				action(window, a, b);
			}
		}
	}
	else
	{
		action(window, a, b);
	}
}

void	action_move(t_win *window, int shift_x, int shift_y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	param->origin_re += shift_x / param->zoom;
	param->origin_im -= shift_y / param->zoom;
	window_redraw(window);
}

void	action_set_palette(t_win *window, int color_scheme, int unused)
{
	(void)unused;
	if (window->color_scheme != color_scheme)
	{
		window->color_scheme = color_scheme;
		fill_palette(window);
		window_redraw(window);
	}
}

void	action_close(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window->is_alive = 0;
	mlx_destroy_image(window->program->mlx_ptr, window->img_ptr);
	mlx_destroy_window(window->program->mlx_ptr, window->win_ptr);
}

void	action_zoom_out(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	if (x < 0 || y < 0)
	{
		x = param->width / 2;
		y = param->height / 2;
	}
	param->origin_re += x / param->zoom * STEP_ZOOM;
	param->origin_im += (param->height - y) / param->zoom * STEP_ZOOM;
	param->zoom /= 1.0 + STEP_ZOOM;
	window_redraw(window);
}

void	action_zoom_in(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	if (x < 0 || y < 0)
	{
		x = param->width / 2;
		y = param->height / 2;
	}
	param->zoom *= 1.0 + STEP_ZOOM;
	param->origin_re -= x / param->zoom * STEP_ZOOM;
	param->origin_im -= (param->height - y) / param->zoom * STEP_ZOOM;
	window_redraw(window);
}

void	action_reset(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window_reset(window);		// TODO: incorporate here
	window_redraw(window);
}

//	key_press
//	esc:
//		destroy_window(window)
//	shift (left):
//		window->program->global_mode |= LEFT_SHIFT_PRESSED;
//	shift (right):
//		window->program->global_mode |= RIGHT_SHIFT_PRESSED;
//	-, - (numpad):
//		zoom_out(window)
//	=, + (numpad):
//		zoom_in(window)
//	[:
//
//	]:
//
//	arrow_up:
//	arrow_right:
//	arrow_down:
//	arrow_left:
//
//	space:
//		reset(window)
//	h:
//	
//	i:
//
