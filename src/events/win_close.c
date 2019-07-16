/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:10:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"		// TODO: or "events_private.h"

int		win_close(void *window)
{
	t_prog *const	program = ((t_win *)window)->program;
	int				window_index;

	apply(action_close, window, UNUSED, UNUSED);
	window_index = program->window_count;
	while (window_index--)
	{
		if (program->windows[window_index].is_alive)
		{
			return (0);
		}
	}
	// TODO: free everything, including OpenCL
	system("leaks -q fractol >&2");		/////////////////////////
	exit(EXIT_SUCCESS);
	return (0);
}


