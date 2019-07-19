/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_change_iterations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:01:57 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 18:02:21 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_change_iterations(t_win *window, int direction, int unused)
{
	(void)unused;
	if (window->param.iteration_max > 1 && direction < 0)
	{
		window->param.iteration_max -= 1;
		fill_palette(window);
		window_redraw(window);
	}
	else if (window->param.iteration_max < ITER_MAX && direction > 0)
	{
		window->param.iteration_max += 1;
		fill_palette(window);
		window_redraw(window);
	}
}
