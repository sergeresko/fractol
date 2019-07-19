/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:44 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 19:39:06 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_private.h"

int		mouse_release(int button, int x, int y, void *window)
{
	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
	{
		((t_win *)window)->program->drag_mode = 0;
	}
	return (0);
}
