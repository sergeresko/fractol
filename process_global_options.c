/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_global_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:09:33 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 18:34:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		error_opt_invalid(char const *arg)
{
	ft_putstr_fd("ERROR: Invalid option \"", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\".\n", STDERR_FILENO);
	die();
}

static void		initialize_global_options(t_everything *everything)
{
	int			i;

	i = 0;
	while (i < OPTION_COUNT)
	{
		*(get_opt(i)->addr(everything)) = 0;
		++i;
	}
}

static void		finalize_global_options(t_everything *everything)
{
	int			i;
	t_opt const	*opt;
	int			*addr;

	i = 0;
	while (i < OPTION_COUNT)
	{
		opt = get_opt(i);
		addr = opt->addr(everything);
		if (!(*addr))
		{
			*addr = opt->default_value;
		}
		++i;
	}
}

char			**process_global_options(t_everything *everything, char **av)
{
	char const	*arg;
	t_opt const	*opt;

	initialize_global_options(everything);
	while ((arg = *(++av)) && arg[0] == '-')
	{
		if (!(arg[1]) || arg[2] || !(opt = get_opt_by_character(arg[1])))
		{
			error_opt_invalid(arg);
		}
		set_global_option(everything, opt, *(++av));
	}
	finalize_global_options(everything);
	return (av - 1);
}
