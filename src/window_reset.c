/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:37:12 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/23 15:16:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	set window parameters (color, palette, param) according to its options
*/

void			window_reset(t_win *window)
{
	t_param *const	param = &(window->param);

	param->width = window->options[OPT_INDEX_WIDTH];
	param->height = window->options[OPT_INDEX_HEIGHT];
	param->iteration_max = window->options[OPT_INDEX_ITER];
	param->zoom = 100.0;		// TODO: compute according to size and type
	param->origin_re = (param->width + 1) / 2 / param->zoom;
	param->origin_im = (param->height + 1) / 2 / param->zoom;
	param->julia_re0 = 0.356;		// for example
	param->julia_im0 = 0.356;		// for example
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
