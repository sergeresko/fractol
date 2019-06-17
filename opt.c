/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:54:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 12:48:49 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>		// for offsetof
#include "fractol.h"

t_opt const		*opt_info(size_t index)
{
	static t_opt const	opt_array[] = {
		{'w', 480, 4000, 800, offsetof(t_everything, width), offsetof(t_window, width)},
		{'h', 360, 2000, 600, offsetof(t_everything, height), offsetof(t_window, height)},
		{'i', 1, 1000, 100, offsetof(t_everything, iterations), offsetof(t_window, iterations)},
		{'c', 1, 5, 2, offsetof(t_everything, color), offsetof(t_window, color)},
	};

	if (index < sizeof(opt_array) / sizeof(*opt_array))
	{
		return (&(opt_array[index]));
	}
	return (NULL);
}

int				opt_get_global(t_everything const *everything, t_opt const *opt)
{
	return (*(int const *)((char const *)everything + opt->offset_global));
}

void			opt_set_global(t_everything *everything, t_opt const *opt, int value)
{
	*(int *)((char *)everything + opt->offset_global) = value;
}

int				opt_get_local(t_window const *window, t_opt const *opt)
{
	return (*(int const *)((char const *)window + opt->offset_local));
}

void			opt_set_local(t_window *window, t_opt const *opt, int value)
{
	*(int *)((char *)window + opt->offset_local) = value;
}
