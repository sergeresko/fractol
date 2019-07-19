/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/19 19:06:12 by syeresko         ###   ########.fr       */
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

static void	palette_grey(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = window->param.iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(t * 255) << 16
				| (int)(t * 255) << 8
				| (int)(t * 255);
	}
}

static void	palette_bernstein(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;
	double		s;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;		// TODO:
		s = 1.0 - t;
		palette[index] = (int)(9.0 * s * t * t * t * 255) << 16
				| (int)(15.0 * s * s * t * t * 255) << 8
				| (int)(8.5 * s * s * s * t * 255);
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
		color += 0x0042f0;//color += 0x000ff0;
		++index;
	}
	window->palette[index - 1] = 0x000000;		// possible because index increments
}

static void	palette_cos_012(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255);
	}
}

static void	palette_cos_102(t_win *window)
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
		palette[index] = (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255);
	}
}

static void	palette_cos_201(t_win *window)
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
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255);
	}
}

// TODO: bad
static void	palette_cos_021(t_win *window)
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
		palette[index] = (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255);
	}
}

// TODO: so-so
static void	palette_cos_120(t_win *window)
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
		palette[index] = (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 1.0 / 3.0))) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * (t + 2.0 / 3.0))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.5 * 2.0 * M_PI * t)) * 255);
	}
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

static void	palette_cos_test(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(0.5 * (1.0 + cos(2.0 * M_PI * 3.0 * t)) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.0 * M_PI * (3.0 * t + 0.1))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.0 * M_PI * (3.0 * t + 0.2))) * 255);
	}
}
/*
static void	palette_cos_test(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(0.5 * (1.0 + cos(2.0 * M_PI * (3.0 * t + 0.5))) * 255) << 16
				| (int)(0.5 * (1.0 + cos(2.0 * M_PI * (3.0 * t + 0.4))) * 255) << 8
				| (int)(0.5 * (1.0 + cos(2.0 * M_PI * (3.0 * t + 0.2))) * 255);
	}
}
*/
void		fill_palette(t_win *window)
{
	if (window->color_scheme == 1)
	{
		palette_monochrome(window);
	}
	else if (window->color_scheme == 2)
	{
		palette_bernstein(window);
	}
	else if (window->color_scheme == 3)
	{
		palette_my(window);
	}
	else if (window->color_scheme == 4)
	{
		palette_cos_012(window);
	}
	else if (window->color_scheme == 5)
	{
		palette_cos_102(window);
	}
	else if (window->color_scheme == 6)
	{
		palette_cos_201(window);
	}
	else if (window->color_scheme == 7)
	{
		palette_cos_021(window);
	}
	else if (window->color_scheme == 8)
	{
		palette_cos_120(window);
	}
	else if (window->color_scheme == 9)
	{
		palette_cos_210(window);
	}
	else if (window->color_scheme == 10)
	{
		palette_cos_test(window);
		palette_grey(window);
	}
}
