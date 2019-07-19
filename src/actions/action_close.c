/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:35:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 17:35:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <mlx.h>		// or "mlx.h" ?

void	action_close(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window->is_alive = 0;
	mlx_destroy_image(window->program->mlx_ptr, window->img_ptr);
	mlx_destroy_window(window->program->mlx_ptr, window->win_ptr);
	// TODO: free what refers to this window of OpenCL
}
