/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_update_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:03:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:04:54 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	action_update_variable(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	if (window->type->is_variable && !(window->is_fixed))
	{
		window->param.var_re = window->program->var_re;
		window->param.var_im = window->program->var_im;
		window_update(window);
	}
}
