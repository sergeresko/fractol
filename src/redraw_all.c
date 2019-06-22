/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:03:47 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/22 20:25:58 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_cl_palette(t_win *window)
{
	cl_int		err;

	err = clEnqueueWriteBuffer(window->program->cl_commands,
			window->cl_palette, CL_TRUE, 0,
			window->param.iteration_max * sizeof(int), window->palette,
			0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		error1("failed to write to OpenCL buffer");
	}
}

void			set_cl_param(t_win *window)
{
	cl_int		err;

	err = clEnqueueWriteBuffer(window->program->cl_commands,
			window->cl_param, CL_TRUE, 0,
			sizeof(t_param), &(window->param), 0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		error1("failed to write to OpenCL buffer");
	}
}

void			redraw_window(t_win *window)
{
	cl_int		err;

	err = clEnqueueNDRangeKernel(window->program->cl_commands,
			window->cl_kernel, 1, NULL, &(window->cl_global_size), NULL,
			0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		error1("failed to enqueue an OpenCL kernel");
	}
	err = clEnqueueReadBuffer(window->program->cl_commands, window->cl_img,
			CL_TRUE, 0, window->cl_global_size * sizeof(int),
			window->img_data, 0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		error1("failed to read an OpenCL buffer");
	}
	clFinish(window->program->cl_commands);
	//
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
}

void			redraw_all(t_prog *program)
{
	int			window_index;
	t_win		*window;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		set_cl_palette(window);
		set_cl_param(window);
		redraw_window(window);
	}
}
