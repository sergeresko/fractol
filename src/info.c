/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/13 17:00:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*opt_info(int index)
{
	static t_opt const		info[OPT_COUNT] = {
		{WIDTH_CHAR, WIDTH_MIN, WIDTH_MAX, WIDTH_DEFAULT, WIDTH_DESCR},
		{HEIGHT_CHAR, HEIGHT_MIN, HEIGHT_MAX, HEIGHT_DEFAULT, HEIGHT_DESCR},
		{ITER_CHAR, 1, ITER_MAX, ITER_DEFAULT, ITER_DESCR},
		{COLOR_CHAR, 1, COLOR_MAX, COLOR_DEFAULT, COLOR_DESCR},
	};

	return (&(info[index]));
}

t_type const	*type_info(int index)
{
	static t_type const		info[TYPE_COUNT] = {
		{"Julia set", "julia_set", -2.0, 2.0, -2.0, 2.0, 1},
		{"Mandelbrot set", "mandelbrot_set", -2.5, 1.5, -1.5, 1.5, 0},
	};

	return (&(info[index]));
}
