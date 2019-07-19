/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:38:07 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 17:41:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#define ZOOM_STEP	0.1
#define ZOOM_MIN	1.0e-6		// TODO: ?
#define ZOOM_MAX	1.0e16

void	action_zoom_out(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);

	if (param->zoom > ZOOM_MIN)
	{
		if (x < 0 || y < 0)
		{
			x = param->width / 2;
			y = param->height / 2;
		}
		param->origin_re -= x / param->zoom * ZOOM_STEP;
		param->origin_im += y / param->zoom * ZOOM_STEP;
		param->zoom /= 1.0 + ZOOM_STEP;
		window_redraw(window);
	}
}

void	action_zoom_in(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);

	if (param->zoom < ZOOM_MAX)
	{
		if (x < 0 || y < 0)
		{
			x = param->width / 2;
			y = param->height / 2;
		}
		param->zoom *= 1.0 + ZOOM_STEP;
		param->origin_re += x / param->zoom * ZOOM_STEP;
		param->origin_im -= y / param->zoom * ZOOM_STEP;
		window_redraw(window);
	}
}
