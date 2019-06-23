/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		palette_monochrome(t_win *window)
{
	int *const	palette = window->palette;
	int			index;

	index = window->param.iteration_max;
	palette[--index] = 0x000000;		// black
	while (index)
	{
		palette[--index] = 0xffffff;	// white
	}
}

static void		palette_2(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (unsigned)(9.0 * (1 - t) * t * t * t * 255) << 16
				| (unsigned)(15.0 * (1 - t) * (1 - t) * t * t * 255) << 8
				| (unsigned)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
}

void		fill_palette(t_win *window)
{
	if (window->color_scheme == 1)
	{
		palette_monochrome(window);
	}
	if (window->color_scheme == 2)
	{
		palette_2(window);
	}
}
