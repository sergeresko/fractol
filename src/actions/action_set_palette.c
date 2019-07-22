/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_set_palette.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:09:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:05:16 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_set_palette(t_win *window, int color_scheme, int unused)
{
	(void)unused;
	if (window->color_scheme != color_scheme)
	{
		window->color_scheme = color_scheme;
		fill_palette(window);
		window_update(window);
	}
}
