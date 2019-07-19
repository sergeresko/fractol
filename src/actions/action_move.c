/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:00:32 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 18:00:58 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_move(t_win *window, int shift_x, int shift_y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	param->origin_re -= shift_x / param->zoom;
	param->origin_im += shift_y / param->zoom;
	window_redraw(window);
}
