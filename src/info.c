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

#define TITLE_MANDELBROT	"Mandelbrot fractal:   z => z^2 + c"
#define TITLE_MANDELBROT_J	"Mandelbrot Julia set"
#define TITLE_MULTIBROT3	"Multibrot-3 fractal:  z => z^3 + c"
#define TITLE_MULTIBROT3_J	"Multibrot-3 Julia set"
#define TITLE_MULTIBROT4	"Multibrot-4 fractal:  z => z^4 + c"
#define TITLE_MULTIBROT4_J	"Multibrot-4 Julia set"
#define TITLE_TRICORN		"Tricorn fractal:      z => (x - iy)^2 + c"
#define TITLE_TRICORN_J		"Tricorn Julia set"
#define TITLE_BURNINGSHIP	"Burning Ship fractal: z => (|x| - i|y|)^2 + c"
#define TITLE_BURNINGSHIP_J	"Burning Ship Julia set"
#define TITLE_NEWTON3		"Newton-3 fractal:     f(z) = z^3 - 1"
#define TITLE_NEWTON_SIN	"Newton-sin fractal:   f(z) = sin(z) - 1"
#define TITLE_NEWTON8		"Newton-8 fractal:     f(z) = z^8 + 3*z^4 - 4"
#define TITLE_NOVA			"Nova fractal:         f(z) = z^3 - 1"

t_type const	*type_info(int index)
{
	static t_type const	info[TYPE_COUNT] = {	// TODO:
		{TITLE_MANDELBROT, "mandelbrot", -2.5, 1.5, -1.5, 1.5, 0},
		{TITLE_MANDELBROT_J, "mandelbrot_j", -2.0, 2.0, -2.0, 2.0, 1},
		{TITLE_MULTIBROT3, "multibrot3", -1.0, 1.0, -1.5, 1.5, 0},
		{TITLE_MULTIBROT3_J, "multibrot3_j", -1.5, 1.5, -1.5, 1.5, 1},				// OK
		{TITLE_MULTIBROT4, "multibrot4", -1.0, 1.0, -1.5, 1.5, 0},
		{TITLE_MULTIBROT4_J, "multibrot4_j", -1.5, 1.5, -1.5, 1.5, 1},
		{TITLE_TRICORN, "tricorn", -2.0, 2.0, -2.0, 2.0, 0},		// OK
		{TITLE_TRICORN_J, "tricorn_j", -2.0, 2.0, -2.0, 2.0, 1},	// OK
		{TITLE_BURNINGSHIP, "burningship", -2.0, 2.0, -2.0, 2.0, 0},
		{TITLE_BURNINGSHIP_J, "burningship_j", -2.0, 2.0, -2.0, 2.0, 1},
//		{"Negabrot 1", "negabrot_1", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Negabrot 2", "negabrot_2", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Newton p(z) = z^3 - 1", "newton", -1.0, 1.0, -1.5, 1.5, 0},
//		{"Newton 2 variable", "newton2_var", -1.0, 1.0, -1.5, 1.5, 1},
		{TITLE_NEWTON3, "newton3", -1.0, 1.0, -1.5, 1.5, 1},
		{TITLE_NEWTON_SIN, "newton_sin", -1.0, 1.0, -1.5, 1.5, 0},
		{TITLE_NEWTON8, "newton_custom", -1.0, 1.0, -1.5, 1.5, 0},
		{TITLE_NOVA, "newton3_nova", -1.0, 1.0, -1.5, 1.5, 1},		// TODO: not variable
	};

	return (&(info[index]));
}
