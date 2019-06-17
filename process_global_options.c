/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_global_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:09:33 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 17:26:26 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		initialize_global_options(t_everything *everything)
{
	int			opt_index;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		everything->options[opt_index] = 0;
	}
}

static void		finalize_global_options(t_everything *everything)
{
	int			opt_index;
	t_opt const	*opt;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		if (everything->options[opt_index] == 0)
		{
			opt = opt_info(opt_index);
			everything->options[opt_index] = atoi_space(opt->default_value);
		}
	}
}

char			**process_global_options(t_everything *everything, char **av)
{
	char const	*arg;
	int			opt_index;

	initialize_global_options(everything);
	while ((arg = *(++av)) && arg[0] == OPT_CHAR_GLOBAL)
	{
		if (!(arg[1]) || arg[2]
				|| (opt_index = get_opt_index_by_character(arg[1])) < 0)
		{
			error3("invalid option \"", arg, "\"");
		}
		set_global_option(everything, opt_index, *(++av));
	}
	finalize_global_options(everything);
	return (--av);
}
