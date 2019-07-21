/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 21:10:45 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "palettes.h"

/*
static void	palette_cos_012(t_win *window)
{
	palette_periodic(window, 0.0, 1.0 / 3.0, 2.0 / 3.0);
}

static void	palette_cos_102(t_win *window)
{
	palette_periodic(window, 1.0 / 3.0, 0.0, 2.0 / 3.0);
}

static void	palette_cos_201(t_win *window)
{
	palette_periodic(window, 2.0 / 3.0, 0.0, 1.0 / 3.0);
}

static void	palette_cos_210(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	palette[--index] = 0xffffff;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255);
	}
}
*/

void	fill_palette(t_win *window)
{
	static void	(*palette[10])(t_win *) = {
		NULL,
		palette_bernstein,
		palette_cos,
		palette_cos,
		palette_cos,
		palette_cos,
		palette_blue_brown,
		palette_kaleidoscope,
		palette_greyscale,
		palette_monochrome,
	};

	palette[window->color_scheme](window);
}

/*
void		fill_palette(t_win *window)
{
	if (window->color_scheme == 1)
	{
		palette_bernstein(window);
	}
	else if (window->color_scheme == 2)
	{
		palette_cos_012(window);
	}
	else if (window->color_scheme == 3)
	{
		palette_cos_102(window);
	}
	else if (window->color_scheme == 4)
	{
		palette_cos_201(window);
	}
	else if (window->color_scheme == 5)
	{
		palette_cos_210(window);
	}
	else if (window->color_scheme == 6)
	{
		palette_blue_brown(window);
	}
	else if (window->color_scheme == 7)
	{
		palette_kaleidoscope(window);
	}
	else if (window->color_scheme == 8)
	{
		palette_greyscale(window);
	}
	else if (window->color_scheme == 9)
	{
		palette_monochrome(window);
	}
	else if (window->color_scheme == 10)
	{
	}
}
*/
