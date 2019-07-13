/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:37:12 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 14:58:55 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>			// fmin

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

void			window_redraw(t_win *window)
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
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
	if (window->is_menu_shown)
	{
		// TODO:
	}
}

void			redraw_all(t_prog *program)
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
