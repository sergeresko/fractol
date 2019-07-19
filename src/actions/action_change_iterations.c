/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_change_iterations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:01:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 19:43:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_change_iterations(t_win *window, int direction, int unused)
{
	t_param *const	param = &(window->param);

	(void)unused;
	if (param->iteration_max > 1 && direction < 0)
	{
		param->iteration_max -= 1;
		fill_palette(window);
		window_redraw(window);
	}
	else if (param->iteration_max < ITER_MAX && direction > 0)
	{
		param->iteration_max += 1;
		fill_palette(window);
		window_redraw(window);
	}
}
