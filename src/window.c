/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:37:12 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 19:17:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>			// fmin

// OpenCL

void			window_recompute_image(t_win *window)
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

void			window_display_image(t_win *window)
{
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
}

void			window_display_menu(t_win *window)
{
	/* TODO:
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
	*/
	mlx_string_put(window->program->mlx_ptr, window->win_ptr, 10, 30, 0xffffff, "Menu");
	// TODO:
}

void			window_display_info(t_win *window)
{
	// TODO:
	(void)window;	// remove
}

/*
**	set window parameters (color, palette, param) according to its options
*/

void			window_reset(t_win *window)
{
	t_param *const		p = &(window->param);
	t_type const *const	t = window->type;

	p->width = window->options[OPT_INDEX_WIDTH];
	p->height = window->options[OPT_INDEX_HEIGHT];
	p->iteration_max = window->options[OPT_INDEX_ITER];
	p->zoom = fmin(p->width / (t->re_max - t->re_min),
			p->height / (t->im_max - t->im_min));
	p->origin_re = ((p->width / p->zoom) - (t->re_min + t->re_max)) / 2.0;
	p->origin_im = ((p->height / p->zoom) - (t->im_min + t->im_max)) / 2.0;
	p->julia_re0 = 0.356;		// for example
	p->julia_im0 = 0.356;		// for example
	window->color_scheme = window->options[OPT_INDEX_COLOR];
	fill_palette(window);
}

// public

void			window_display(t_win *window)
{
	window_display_image(window);
	if (window->is_menu_shown)
	{
		window_display_menu(window);
	}
	/*if (window->is_info_shown)
	{
		window_display_info(window);
	}*/
}

void			window_redraw(t_win *window)
{
	window_recompute_image(window);
	window_display(window);
}

void			redraw_all(t_prog *program)		// TODO: remove
{
	int			window_index;
	t_win		*window;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		window_redraw(window);
	}
}
