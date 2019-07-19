/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_toggle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:26:23 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 17:27:27 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_toggle_fix(t_win *window, int is_fixed, int unused)
{
	(void)unused;
	window->is_fixed = !is_fixed;
	window_display(window);
}

void	action_toggle_help(t_win *window, int is_help_shown, int unused)
{
	(void)unused;
	window->is_help_shown = !is_help_shown;
	window_display(window);
}

void	action_toggle_status(t_win *window, int is_status_shown, int unused)
{
	(void)unused;
	window->is_status_shown = !is_status_shown;
	window_display(window);
}
