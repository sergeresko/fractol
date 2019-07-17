#include <stdlib.h>
#include <mlx.h>		// only for action_close
//#include "fractol.h"

//#include "actions.h"

#include "window.h"

#include "actions.h"		// only STEP_ZOOM

/*
#define LEFT_SHIFT_PRESSED	(1 << 0)
#define RIGHT_SHIFT_PRESSED	(1 << 1)

#define STEP_ARROW_MOVE		32
#define STEP_ZOOM			0.1

#define UNUSED				0

typedef void	(*t_func)(t_win *, int, int);
*/

void	action_move(t_win *window, int shift_x, int shift_y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	param->origin_re -= shift_x / param->zoom;
	param->origin_im += shift_y / param->zoom;		// ?
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
	// TODO: free what refers to this window of OpenCL
}

void	action_zoom_out(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);

//	if (param->zoom > 1.0)		// ZOOM_MIN
//	{
		if (x < 0 || y < 0)
		{
			x = param->width / 2;
			y = param->height / 2;
		}
		param->origin_re -= x / param->zoom * STEP_ZOOM;
		param->origin_im += y / param->zoom * STEP_ZOOM;	//
		param->zoom /= 1.0 + STEP_ZOOM;
		window_redraw(window);
//	}
}

void	action_zoom_in(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);

	if (param->zoom < 1.0e16)	// ZOOM_MAX
	{
		if (x < 0 || y < 0)
		{
			x = param->width / 2;
			y = param->height / 2;
		}
		param->zoom *= 1.0 + STEP_ZOOM;
		param->origin_re += x / param->zoom * STEP_ZOOM;
		param->origin_im -= y / param->zoom * STEP_ZOOM;	//
		window_redraw(window);
	}
}

void	action_reset(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window_reset(window);		// TODO: incorporate here
	window_redraw(window);
}

void	action_update_julia(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	if (window->type->is_variable && !(window->is_fixed))
	{
		window->param.julia_re0 = window->program->julia_re;
		window->param.julia_im0 = window->program->julia_im;
		window_redraw(window);
	}
}

void	action_change_iterations(t_win *window, int direction, int unused)
{
	(void)unused;
	if (window->param.iteration_max > 1 && direction < 0)
	{
		window->param.iteration_max -= 1;
		fill_palette(window);
		window_redraw(window);
	}
	else if (window->param.iteration_max < ITER_MAX && direction > 0)
	{
		window->param.iteration_max += 1;
		fill_palette(window);
		window_redraw(window);
	}
}

// action_toggle..., action_shift...

void	action_toggle_fix(t_win *window, int is_fixed, int unused)
{
	(void)unused;
	window->is_fixed = !is_fixed;
	window_display(window);
}

void	action_shift_help(t_win *window, int is_help_shown, int frame)
{
	if (is_help_shown && window->is_help_shown)
	{
		window_display_with_shifted_help(window, -25 * frame, 0);
	}
	else if (!is_help_shown && !(window->is_help_shown))
	{
		window_display_with_shifted_help(window, 25 * frame - 200, 0);
	}
}

void	action_toggle_help(t_win *window, int is_help_shown, int unused)
{
	(void)unused;
	window->is_help_shown = !is_help_shown;
	window_display(window);
}

void	action_shift_status(t_win *window, int is_status_shown, int frame)
{
	if (is_status_shown && window->is_status_shown)
	{
		window_display_with_shifted_status(window, 0, 8 * frame);
	}
	else if (!is_status_shown && !(window->is_status_shown))
	{
		window_display_with_shifted_status(window, 0, 40 - 8 * frame);
	}
}

void	action_toggle_status(t_win *window, int is_status_shown, int unused)
{
	(void)unused;
	window->is_status_shown = !is_status_shown;
	window_display(window);
}
