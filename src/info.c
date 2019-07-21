/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/18 19:53:20 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*opt_info(int index)
{
	static t_opt const	info[OPT_COUNT] = {
		{WIDTH_CHAR, WIDTH_MIN, WIDTH_MAX, WIDTH_DEFAULT, WIDTH_DESCR},
		{HEIGHT_CHAR, HEIGHT_MIN, HEIGHT_MAX, HEIGHT_DEFAULT, HEIGHT_DESCR},
		{ITER_CHAR, 1, ITER_MAX, ITER_DEFAULT, ITER_DESCR},
		{COLOR_CHAR, 1, COLOR_MAX, COLOR_DEFAULT, COLOR_DESCR},
	};

	return (&(info[index]));
}

t_type const	*type_info(int index)
{
	static t_type const	info[TYPE_COUNT] = {	// TODO:
		{"Mandelbrot fractal", "mandelbrot", -2.5, 1.5, -1.5, 1.5, 0},
		{"Mandelbrot Julia set", "mandelbrot_j", -2.0, 2.0, -2.0, 2.0, 1},
		{"Multibrot-3 fractal", "multibrot3", -1.0, 1.0, -1.5, 1.5, 0},
		{"Multibrot-3 Julia set 3", "multibrot3_j", -1.5, 1.5, -1.5, 1.5, 1},				// OK
		{"Multibrot-4 fractal", "multibrot4", -1.0, 1.0, -1.5, 1.5, 0},
		{"Multibrot-4 Julia set", "multibrot4_j", -1.5, 1.5, -1.5, 1.5, 1},
		{"Tricorn fractal", "tricorn", -2.0, 2.0, -2.0, 2.0, 0},		// OK
		{"Tricorn Julia set", "tricorn_j", -2.0, 2.0, -2.0, 2.0, 1},	// OK
		{"Burning Ship fractal", "burningship", -2.0, 2.0, -2.0, 2.0, 0},
		{"Burning Ship Julia set", "burningship_j", -2.0, 2.0, -2.0, 2.0, 1},
//		{"Negabrot 1", "negabrot_1", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Negabrot 2", "negabrot_2", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Newton p(z) = z^3 - 1", "newton", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Newton 2 variable", "newton2_var", -1.0, 1.0, -1.5, 1.5, 1},
		{"Newton-3 fractal", "newton3", -1.0, 1.0, -1.5, 1.5, 1},
		{"Newton-sin fractal [p(z) = sin(z) - 1]", "newton_sin", -1.0, 1.0, -1.5, 1.5, 0},
		{"Newton-8 fractal [p(z) = z^8 + 3 * z^4 - 4]", "newton_custom", -1.0, 1.0, -1.5, 1.5, 0},
		{"Nova fractal", "newton3_nova", -1.0, 1.0, -1.5, 1.5, 1},		// TODO: not variable
	};

	return (&(info[index]));
}
