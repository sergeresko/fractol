/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:17:02 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:24:57 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

void	image_recompute(t_win *window)
{
	clEnqueueWriteBuffer(window->program->opencl_commands,
			window->opencl_palette, CL_TRUE, 0,
			window->param.iteration_max * sizeof(int),
			window->palette, 0, NULL, NULL);
	clEnqueueWriteBuffer(window->program->opencl_commands,
			window->opencl_param, CL_TRUE, 0, sizeof(t_param),
			&(window->param), 0, NULL, NULL);
	clEnqueueNDRangeKernel(window->program->opencl_commands,
			window->opencl_kernel, 1, NULL, &(window->opencl_global_size),
			NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(window->program->opencl_commands, window->opencl_img,
			CL_TRUE, 0, window->opencl_global_size * sizeof(int),
			window->img_data, 0, NULL, NULL);
	clFinish(window->program->opencl_commands);
}

void	image_display(t_win *window)
{
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			window->img_ptr, 0, 0);
}
