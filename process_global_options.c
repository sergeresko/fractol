/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_global_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:09:33 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 12:16:34 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		initialize_global_options(t_everything *everything)
{
	int			i;

	i = 0;
	while (i < OPTION_COUNT)
	{
		opt_set_global(everything, opt_info(i), 0);
		++i;
	}
}

static void		finalize_global_options(t_everything *everything)
{
	int			i;
	t_opt const	*opt;

	i = 0;
	while (i < OPTION_COUNT)
	{
		opt = opt_info(i++);
		if (opt_get_global(everything, opt) == 0)
		{
			opt_set_global(everything, opt, opt->default_value);
		}
	}
}

char			**process_global_options(t_everything *everything, char **av)
{
	char const	*arg;
	t_opt const	*opt;

	initialize_global_options(everything);
	while ((arg = *(++av)) && arg[0] == OPT_CHAR_GLOBAL)
	{
		if (!(arg[1]) || arg[2] || !(opt = get_opt_by_character(arg[1])))
		{
			error3("invalid option \"", arg, "\"");
		}
		set_global_option(everything, opt, *(++av));
	}
	finalize_global_options(everything);
	return (--av);
}
