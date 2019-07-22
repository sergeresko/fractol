/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_palette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:10:16 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 13:29:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "palettes.h"		// included only here

void	fill_palette(t_win *window)
{
	static void	(*palette[10])(t_win *) = {
		NULL,
		palette_bernstein,
		palette_periodic,
		palette_periodic,
		palette_periodic,
		palette_periodic,
		palette_blue_brown,
		palette_kaleidoscope,
		palette_greyscale,
		palette_monochrome,
	};

	palette[window->color_scheme](window);
}
