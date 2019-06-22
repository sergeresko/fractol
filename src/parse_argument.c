/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:28:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/22 19:32:43 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	tell whether string `sub` is a subsequence of string `full`
**	(comparison is case insensitive)
*/

static int		is_subseq(char const *full, char const *sub)
{
	char		s;
	char		f;

	while ((s = ft_tolower(*(sub++))))
	{
		while ((f = ft_tolower(*(full++))) != s)
		{
			if (!f)
			{
				return (0);
			}
		}
	}
	return (1);
}

/*
**	for a given name, return the corresponding type index;
**	terminate with error if the name is ambiguous;
**	return -1 if the name is invalid
*/

static int		get_type_index_by_title(char const *title)
{
	int			index;
	int			i;

	index = -1;
	i = TYPE_COUNT;
	while (i--)
	{
		if (is_subseq(type_info(i)->title, title))
		{
			if (index >= 0)
			{
				error3("title \"", title, "\" is ambiguous");
			}
			index = i;
		}
	}
	return (index);
}

/*
**	TODO: describe
*/

static void		parse_components(t_win *window, char **components)
{
	int const	type_index = get_type_index_by_title(*components);
	char		*component;
	int			opt_index;

	if (type_index < 0)
	{
		error3("\"", *components, "\" is not a valid title");
	}
	window->type = type_info(type_index);	// `window->type` initialization
	while ((component = *(++components)))
	{
		opt_index = OPT_COUNT;
		while (opt_index-- && opt_info(opt_index)->character != component[0])
			;
		if (opt_index < 0)
		{
			error3("invalid local option \".", component, "\"");
		}
		set_option(window->options, OPT_PREFIX_LOCAL, opt_index, component + 1);
	}
}

/*
**	TODO: describe
*/

void			parse_argument(t_win *window, char const *arg)
{
	char		**components;

	if (!(arg[0]) || arg[0] == OPT_PREFIX_LOCAL)
	{
		error3("empty title in argument \"", arg, "\"");
	}
	components = ft_strsplit(arg, OPT_PREFIX_LOCAL);
	if (!components)
	{
		error1("ft_strsplit failed");	// when can this happen ?
	}
	parse_components(window, components);
	ft_strsplit_clear(components);
}
