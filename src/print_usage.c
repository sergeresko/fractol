/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:31 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:35:54 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"	// TODO:
#include "libft.h"		// ft_putstr_fd, ft_putchar_fd, ft_strcpy

static void print_usage_titles(void)
{
	int		type_index;

	type_index = 0;
	while (type_index < TYPE_COUNT)
	{
		ft_putstr_fd("    ", STDERR_FILENO);
		ft_putstr_fd(type_info(type_index)->title, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		++type_index;
	}
}

static void	print_usage_options(void)
{
	char		str[80];
	int			opt_index;
	t_opt const	*opt;

	ft_putstr_fd(
			"    global    local      range      default      description\n\n",
			STDERR_FILENO);
	ft_strcpy(str, "    ## <N>    ##<N>    ###...####     ###     ");
	str[4] = OPT_PREFIX_GLOBAL;
	str[14] = OPT_PREFIX_LOCAL;
	opt_index = 0;
	while (opt_index < OPT_COUNT)
	{
		opt = opt_info(opt_index);
		str[5] = opt->character;
		str[15] = opt->character;
		sprintf_int_right(opt->min_value, str + 23, 3);
		sprintf_int_left(opt->max_value, str + 29, 4);
		sprintf_int_right(opt->default_value, str + 38, 3);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(opt->description, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		++opt_index;
	}
}

static void	print_usage_examples(void)
{
	// TODO: examples	
}

void		print_usage(void)
{
	ft_putstr_fd(
			"usage: ./fractol [<global options>] <title>[<local options>] ...\n"
			"\nTitles:\n\n", STDERR_FILENO);
	print_usage_titles();
	ft_putstr_fd("\nA title may be shortened to any unambiguous subsequence.\n"
			"Several titles result in several windows.\n"
			"\nOptions:\n\n", STDERR_FILENO);
	print_usage_options();
	ft_putstr_fd("\nGlobal options apply to all windows "
			"unless overriden by local options.\n"
			"\nExamples:\n\n", STDERR_FILENO);
	print_usage_examples();
	ft_putstr_fd("\nPress H when running the program "
			"to see the list of controls.\n", STDERR_FILENO);
}
