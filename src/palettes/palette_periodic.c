/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_periodic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:30:27 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 16:02:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

#define COLOR_WHITE		0xffffff

static void	palette_cos(t_win *window, double r, double g, double b)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	palette[--index] = COLOR_WHITE;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)((1.0 + cos(5.0 * M_PI * (t + r))) * 127.5) << 16
				| (int)((1.0 + cos(5.0 * M_PI * (t + g))) * 127.5) << 8
				| (int)((1.0 + cos(5.0 * M_PI * (t + b))) * 127.5);
	}
}

void		palette_periodic(t_win *window)
{
	static double	phases[][3] = {
		{0.0 / 3.0, 1.0 / 3.0, 2.0 / 3.0},
		{1.0 / 3.0, 0.0 / 3.0, 2.0 / 3.0},
		{2.0 / 3.0, 0.0 / 3.0, 1.0 / 3.0},
		{2.0 / 3.0, 1.0 / 3.0, 0.0 / 3.0},
	};
	double *const	phase = phases[window->color_scheme - 2];

	palette_cos(window, phase[0], phase[1], phase[2]);
}
