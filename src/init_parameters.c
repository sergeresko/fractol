/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/22 19:58:02 by syeresko         ###   ########.fr       */
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

static void		fill_palette(t_win *window)
{
	if (window->color == 1)
	{
		palette_monochrome(window);
	}
	if (window->color == 2)
	{
		palette_2(window);
	}
}

////////////////////////////////

static void		reset_window_parameters(t_win *window)
{
	t_param *const	param = &(window->param);

	param->width = window->options[OPT_INDEX_WIDTH];
	param->height = window->options[OPT_INDEX_HEIGHT];
	param->iteration_max = window->options[OPT_INDEX_ITER];
	param->zoom = 100.;		// TODO: compute according to size and type
	param->origin_re = (param->width + 1) / 2 / param->zoom;
	param->origin_im = (param->height + 1) / 2 / param->zoom;
	param->julia_re0 = 0.356;		// for example
	param->julia_im0 = 0.356;		// for example

	window->color = window->options[OPT_INDEX_COLOR];
	fill_palette(window);
}

void			init_parameters(t_prog *program)
{
	int			window_index;
	t_win		*window;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		reset_window_parameters(window);
	}
}
