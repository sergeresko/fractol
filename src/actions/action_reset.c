/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:08:11 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 18:08:38 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_reset(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window_reset(window);		// TODO: incorporate here
	window_redraw(window);
}
