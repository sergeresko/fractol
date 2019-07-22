/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:27:53 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 16:29:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_animate_help(t_win *window, int is_help_shown, int frame)
{
	if (is_help_shown && (window->is_help_shown))
	{
		window_display_shift_help(window,
				(0 - frame) * HELP_ANIMATION_STEP, 0);
	}
	else if (!is_help_shown && !(window->is_help_shown))
	{
		window_display_shift_help(window,
				(frame - HELP_FRAME_COUNT) * HELP_ANIMATION_STEP, 0);
	}
}

void	action_animate_status(t_win *window, int is_status_shown, int frame)
{
	if (is_status_shown && window->is_status_shown)
	{
		window_display_shift_status(window,
				0, (frame - 0) * STATUS_ANIMATION_STEP);
	}
	else if (!is_status_shown && !(window->is_status_shown))
	{
		window_display_shift_status(window,
				0, (STATUS_FRAME_COUNT - frame) * STATUS_ANIMATION_STEP);
	}
}
