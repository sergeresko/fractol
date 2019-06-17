/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 18:20:04 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*opt_info(int index)
{
	static t_opt const	info[OPT_COUNT] = {
		{'w', "480", "4000", "800", "width in pixels", OPT_INDEX_WIDTH},
		{'h', "360", "2000", "600", "height in pixels", OPT_INDEX_HEIGHT},
		{'i', "  1", "1000", "100", "number of iterations", OPT_INDEX_ITER},
		{'c', "  1", "5   ", "  2", "color palette", OPT_INDEX_COLOR},
	};

	return (&(info[index]));
}
