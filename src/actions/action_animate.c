/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:27:53 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 17:28:49 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_animate_help(t_win *window, int is_help_shown, int frame)
{
	if (is_help_shown && window->is_help_shown)
	{
		window_display_shift_help(window,
				HELP_ANIMATION_STEP * (0 - frame), 0);
	}
	else if (!is_help_shown && !(window->is_help_shown))
	{
		window_display_shift_help(window,
				HELP_ANIMATION_STEP * (frame - HELP_FRAME_COUNT), 0);
	}
}

void	action_animate_status(t_win *window, int is_status_shown, int frame)
{
	if (is_status_shown && window->is_status_shown)
	{
		window_display_shift_status(window,
				0, STATUS_ANIMATION_STEP * (frame - 0));
	}
	else if (!is_status_shown && !(window->is_status_shown))
	{
		window_display_shift_status(window,
				0, STATUS_ANIMATION_STEP * (STATUS_FRAME_COUNT - frame));
	}
}
