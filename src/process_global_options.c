/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_global_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:09:33 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 19:38:43 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// might take `program->options`
static void		initialize_global_options(t_prog *program)
{
	int			opt_index;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		program->options[opt_index] = 0;
	}
}

// might take `program->options`
static void		finalize_global_options(t_prog *program)
{
	int			opt_index;
	t_opt const	*opt;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		if (program->options[opt_index] == 0)
		{
			opt = opt_info(opt_index);
			program->options[opt_index] = opt->default_value;
		}
	}
}

char			**process_global_options(t_prog *program, char **av)
{
	char const	*arg;
	int			opt_index;

	initialize_global_options(program);
	while ((arg = *(++av)) && arg[0] == OPT_CHAR_GLOBAL)
	{
		if (!(arg[1]) || arg[2]
				|| (opt_index = get_opt_index_by_character(arg[1])) < 0)
		{
			error3("invalid global option \"", arg, "\"");
		}
		set_option(program->options, OPT_CHAR_GLOBAL, opt_index, *(++av));
	}
	finalize_global_options(program);
	return (--av);
}
