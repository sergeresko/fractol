/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:31 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 19:45:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		print_usage_options(void)
{
	char		str[80];
	int			opt_index;
	t_opt const	*opt;

	ft_putstr_fd("    global    local      range      default", STDERR_FILENO);
	ft_putstr_fd("      description\n\n", STDERR_FILENO);
	ft_strcpy(str, "    ** <N>    **<N>    ***...****     ***     ");
	str[4] = OPT_CHAR_GLOBAL;
	str[14] = OPT_CHAR_LOCAL;
	opt_index = 0;
	while (opt_index < OPT_COUNT)
	{
		opt = opt_info(opt_index);
		str[5] = opt->character;
		str[15] = opt->character;
		sprintf_int_right(opt->min_value, str + 23, 3);
		sprintf_int_left(opt->max_value, str + 29, 4);
		sprintf_int_right(opt->default_value, str + 38, 3);
//		ft_strncpy(str + 23, opt->min_value, 3);
//		ft_strncpy(str + 29, opt->max_value, 4);
//		ft_strncpy(str + 38, opt->default_value, 3);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(opt->description, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		++opt_index;
	}
}

void			print_usage(void)
{
	ft_putstr_fd("usage: ./fractol [<global options>] "
			"<type>[<local options>] ...\n\n", STDERR_FILENO);
	// TODO:
	print_usage_options();
	// TODO:
}
