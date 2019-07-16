/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 20:39:39 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>		// cos

static void	palette_monochrome(t_win *window)
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

static void	palette_2(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;		// TODO:
		palette[index] = (unsigned)(9.0 * (1 - t) * t * t * t * 255) << 16
				| (unsigned)(15.0 * (1 - t) * (1 - t) * t * t * 255) << 8
				| (unsigned)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
}

static void	palette_my(t_win *window)	// TODO:
{
	int		color;
	int		index;

	color = 0x7f00ff;
	index = 0;
	while (index < window->param.iteration_max)
	{
		window->palette[index] = color;
		color += 0x000ff0;
		++index;
	}
	window->palette[index - 1] = 0x000000;		// possible because index increments
}

static void	palette_cos(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (unsigned)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255) << 16
				| (unsigned)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255) << 8
				| (unsigned)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255);
	}
}

void		fill_palette(t_win *window)
{
	if (window->color_scheme == 1)
	{
		palette_monochrome(window);
	}
	else if (window->color_scheme == 2)
	{
		palette_2(window);
	}
	else if (window->color_scheme == 3)
	{
		palette_my(window);
	}
	else if (window->color_scheme == 4)
	{
		palette_cos(window);
	}
}
