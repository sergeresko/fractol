/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:53 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 18:05:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"

int		mouse_move(int x, int y, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;
	t_param *const	param = &(((t_win *)window)->param);

	if (program->drag_mode)
	{
		apply(action_move, window, x - program->drag_x, y - program->drag_y);
		program->drag_x = x;
		program->drag_y = y;
	}
	else
	{
		program->var_re = param->origin_re + x / param->zoom;
		program->var_im = param->origin_im - y / param->zoom;
		apply(action_update_variable, window, UNUSED, UNUSED);
	}
	return (0);
}
