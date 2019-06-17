/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_global_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:30:31 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 17:32:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO: maybe use `t_opt const *opt` and `opt->character`
static void		error_opt(char const *message, char opt_character)
{
	ft_putstr_fd(ERROR_START, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(" \"-", STDERR_FILENO);
	ft_putchar_fd(opt_character, STDERR_FILENO);
	ft_putstr_fd("\"" ERROR_END, STDERR_FILENO);
	die();
}

void			set_global_option(t_everything *everything,
											int opt_index, char const *arg)
{
	int			value;
	t_opt const	*opt;

	opt = opt_info(opt_index);
	if (everything->options[opt_index] != 0)
	{
		error_opt("multiple options", opt->character);
	}
	if (!arg)
	{
		error_opt("no value for option", opt->character);
	}
	value = atoi_positive(arg);
	if (value < atoi_space(opt->min_value) || value > atoi_space(opt->max_value))
	{
		error_opt("invalid value for option", opt->character);
	}
	everything->options[opt_index] = value;
}
