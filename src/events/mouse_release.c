/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:44 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:09:25 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"

int		mouse_release(int button, int x, int y, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;	// unneeded?

	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
	{
		program->drag_mode = 0;
	}
	return (0);
}
