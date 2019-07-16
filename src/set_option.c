/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:30:31 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:33:43 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"		// ft_strcpy

// TODO: maybe use `t_opt const *opt` and `opt->character`
static void	error_opt(char const *message, char opt_prefix, char opt_char)
{
	char	str[5];

	ft_strcpy(str, "\"##\"");
	str[1] = opt_prefix;
	str[2] = opt_char;
	error3(message, " ", str);
}

/*
**	if the string represents a positive number in the range of `int`,
**	return this number; otherwise return zero
*/

static int	atoi_positive(char const *str)
{
	int		value;
	char	c;

	value = 0;
	while ((c = *(str++)))
	{
		if (c < '0' || c > '9' || (value = value * 10 + (int)(c - '0')) < 0)
		{
			return (0);
		}
	}
	return (value);
}

/*
**	TODO: describe
*/

void		set_option(int *options, char opt_prefix,
											int opt_index, char const *arg)
{
	int			value;
	t_opt const	*opt;

	opt = opt_info(opt_index);
	if (options[opt_index] != 0)
	{
		error_opt("multiple options", opt_prefix, opt->character);
	}
	if (!arg || !(*arg))
	{
		error_opt("no value for option", opt_prefix, opt->character);
	}
	value = atoi_positive(arg);
	if (value < opt->min_value || value > opt->max_value)
	{
		error_opt("invalid value for option", opt_prefix, opt->character);
	}
	options[opt_index] = value;
}
