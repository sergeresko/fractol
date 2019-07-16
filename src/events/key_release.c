/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:30:18 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 21:11:01 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "actions.h"		// LEFT_SHIFT_PRESSED, RIGHT_SHIFT_PRESSED
#include "events_private.h"

int		key_release(int key, void *window)
{
	t_prog *const	program = ((t_win *)window)->program;	// unneeded?

	if (key == KEY_SHIFT_LEFT)
	{
		program->global_mode &= ~LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		program->global_mode &= ~RIGHT_SHIFT_PRESSED;
	}
	return (0);
}
