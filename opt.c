/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 14:07:03 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*opt_info(size_t index)
{
	static t_opt const	opt_array[OPT_COUNT] = {
		{'w', "480", "4000", "800", "width in pixels", OPT_INDEX_WIDTH},
		{'h', "360", "2000", "600", "height in pixels", OPT_INDEX_HEIGHT},
		{'i', "  1", "1000", "100", "number of iterations", OPT_INDEX_ITER},
		{'c', "  1", "5   ", "  2", "color palette", OPT_INDEX_COLOR},
	};

	return (index < OPT_COUNT ? &(opt_array[index]) : NULL);
}

int				opt_get(int const *options, t_opt const *opt)
{
	return (options[opt->index]);
}

void			opt_set(int *options, t_opt const *opt, int value)
{
	options[opt->index] = value;
}
