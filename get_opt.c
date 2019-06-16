/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 19:44:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		*get_width_address(t_everything *everything)
{
	return (&(everything->width));
}

static int		*get_height_address(t_everything *everything)
{
	return (&(everything->height));
}

static int		*get_iterations_address(t_everything *everything)
{
	return (&(everything->iterations));
}

static int		*get_color_address(t_everything *everything)
{
	return (&(everything->color));
}

t_opt const		*get_opt(int index)
{
	static t_opt const	options[OPTION_COUNT] = {
		{WIDTH_CHAR, WIDTH_MIN, WIDTH_MAX, WIDTH_DEF, &get_width_address},
		{HEIGHT_CHAR, HEIGHT_MIN, HEIGHT_MAX, HEIGHT_DEF, &get_height_address},
		{ITER_CHAR, ITER_MIN, ITER_MAX, ITER_DEF, &get_iterations_address},
		{COLOR_CHAR, COLOR_MIN, COLOR_MAX, COLOR_DEF, &get_color_address},
	};

	return (&(options[index]));
}
