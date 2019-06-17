/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 12:18:23 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// for offsetof
#include "fractol.h"

t_opt const		*opt_info(int index)
{
	static t_opt const	opt_array[] = {
		{WIDTH_CHAR, WIDTH_MIN, WIDTH_MAX, WIDTH_DEFAULT,
			offsetof(t_everything, width), offsetof(t_window, width)},
		{HEIGHT_CHAR, HEIGHT_MIN, HEIGHT_MAX, HEIGHT_DEFAULT,
			offsetof(t_everything, height), offsetof(t_window, height)},
		{ITER_CHAR, ITER_MIN, ITER_MAX, ITER_DEFAULT,
			offsetof(t_everything, iterations), offsetof(t_window, iterations)},
		{COLOR_CHAR, COLOR_MIN, COLOR_MAX, COLOR_DEFAULT,
			offsetof(t_everything, color), offsetof(t_window, color)},
	};

	return (&(opt_array[index]));
}

int				opt_get_global(t_everything const *everything, t_opt const *opt)
{
	return (*(int const *)((char const *)everything + opt->offset_global));
}

void			opt_set_global(t_everything *everything, t_opt const *opt, int value)
{
	*(int *)((char *)everything + opt->offset_global) = value;
}

int				opt_get_local(t_everything const *everything, t_opt const *opt)
{
	return (*(int const *)((char const *)everything + opt->offset_local));
}

void			opt_set_local(t_everything *everything, t_opt const *opt, int value)
{
	*(int *)((char *)everything + opt->offset_local) = value;
}
