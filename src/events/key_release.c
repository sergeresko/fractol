/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:18 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 19:39:40 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "actions.h"		// LEFT_SHIFT_PRESSED, RIGHT_SHIFT_PRESSED
#include "events_private.h"

int		key_release(int key, void *window)
{
	if (key == KEY_SHIFT_LEFT)
	{
		((t_win *)window)->program->global_mode &= ~LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		((t_win *)window)->program->global_mode &= ~RIGHT_SHIFT_PRESSED;
	}
	return (0);
}
