/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:20:52 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 19:33:41 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

/*
**	apply the action to the window or, if in global mode, to all windows
*/

void	apply(t_act action, t_win *window, int a, int b)
{
	t_prog *const	program = window->program;
	int				window_index;

	if (program->global_mode)
	{
		window_index = program->window_count;
		while (window_index--)
		{
			window = &(program->windows[window_index]);
			if (window->is_alive)
			{
				action(window, a, b);
			}
		}
	}
	else
	{
		action(window, a, b);
	}
}
