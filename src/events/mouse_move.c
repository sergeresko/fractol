/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:53 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 21:09:51 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
#include "actions.h"	// TODO: or "events_private.h"
#include <math.h>			// fmin

static void	set_julia_parameter(int x, int y, t_win *window)	// TODO:
{
	t_param *const	param = &(window->param);

	window->program->julia_re = param->origin_re + x / param->zoom;
	window->program->julia_im = param->origin_im - y / param->zoom;
}

int			mouse_move(int x, int y, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;

	/*
	if (x < 0 || x >= window->param.width
			|| y < 0 || y >= window->param.height)
	{
		return (0);
	}*/
	/*
	int		id;
	id = window->program->window_count;
	while (window != &(window->program->windows[--id]))
		;
	ft_printf("mouse_move (window %d)    x: %4d    y: %4d\n", id + 1, x, y);*/
	if (program->drag_mode)
	{
		apply(action_move, window, x - program->drag_x, y - program->drag_y);
		program->drag_x = x;
		program->drag_y = y;
	}
	else	// TODO:
	{
		set_julia_parameter(x, y, window);
		apply(action_update_julia, window, UNUSED, UNUSED);
	}
	return (0);
}
