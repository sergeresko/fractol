/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:37:12 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/18 13:05:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"
//#include "fractol.h"
#include <math.h>			// fmin

// OpenCL

void	window_recompute_image(t_win *window)
{
	clEnqueueWriteBuffer(window->program->cl_commands, window->cl_palette,
			CL_TRUE, 0, window->param.iteration_max * sizeof(int),
			window->palette, 0, NULL, NULL);
	clEnqueueWriteBuffer(window->program->cl_commands, window->cl_param,
			CL_TRUE, 0, sizeof(t_param), &(window->param), 0, NULL, NULL);
	clEnqueueNDRangeKernel(window->program->cl_commands, window->cl_kernel,
			1, NULL, &(window->cl_global_size), NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(window->program->cl_commands, window->cl_img,
			CL_TRUE, 0, window->cl_global_size * sizeof(int),
			window->img_data, 0, NULL, NULL);
	clFinish(window->program->cl_commands);
}

// MLX

void	window_display_image(t_win *window)
{
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
}

/*
**	set window parameters (color, palette, param) according to its options
*/

void	window_reset(t_win *window)
{
	t_param *const		p = &(window->param);
	t_type const *const	t = window->type;

	p->width = window->options[OPT_INDEX_WIDTH];
	p->height = window->options[OPT_INDEX_HEIGHT];
	p->iteration_max = window->options[OPT_INDEX_ITER];
	p->zoom = fmin(p->width / (t->re_max - t->re_min),
			p->height / (t->im_max - t->im_min));
	p->origin_re = 0.5 * (t->re_min + t->re_max - p->width / p->zoom);
	p->origin_im = 0.5 * (t->im_min + t->im_max + p->height / p->zoom);
	p->var_re = 0.356;		// for example
	p->var_im = 0.356;		// for example
	window->color_scheme = window->options[OPT_INDEX_COLOR];
	fill_palette(window);
}

// public

#define HELP_X		10
#define HELP_Y		10

#define STATUS_X	10
#define STATUS_Y	(-44)

void	window_display(t_win *window)
{
	window_display_image(window);
	if (window->is_help_shown)
	{
		help_display(window, HELP_X, HELP_Y);
	}
	if (window->is_status_shown)
	{
		status_display(window, STATUS_X, window->param.height + STATUS_Y);
	}
}

void	window_display_shift_help(t_win *window, int shift_x, int shift_y)
{
	window_display_image(window);
	help_display(window, HELP_X + shift_x, HELP_Y + shift_y);
	if (window->is_status_shown)
	{
		status_display(window, STATUS_X, window->param.height + STATUS_Y);
	}
}

void	window_display_shift_status(t_win *window, int shift_x, int shift_y)
{
	window_display_image(window);
	if (window->is_help_shown)
	{
		help_display(window, HELP_X, HELP_Y);
	}
	status_display(window,
			STATUS_X + shift_x, window->param.height + STATUS_Y + shift_y);
}

void	window_redraw(t_win *window)		// window_update
{
	window_recompute_image(window);
	window_display(window);
}
