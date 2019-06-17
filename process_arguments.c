/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 11:51:06 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define FRACTAL_TYPE_COUNT	2

void		error(char const *message)
{
	ft_putstr_fd(ERROR_START, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ERROR_END, STDERR_FILENO);
	die();
}

t_info const	*get_info(int index)
{
	static t_info const		info_array[] = {
		{"julia", "Julia set"},
		{"mandelbrot", "Mandelbrot set"},
	};

	return (&info_array[index]);
}

t_info const	*get_info_by_name(char const *name)
{
	int			index;
	int			i;

	index = 0;
	i = 0;
	while (i < FRACTAL_TYPE_COUNT)
	{
		if (is_subseq(get_info(i)->argument, name))
		{
			if (index)
			{
				error3("fractal name \"", name, "\" is ambiguous");
			}
			index = i;
		}
		++i;
	}
	return (index ? get_info(index) : NULL);
}

void		parse_components(t_everything *everything, char **components)
{
	t_info const	*info;

	info = get_info_by_name(components[0]);
	if (!info)
	{
		error3("\"", components[0], "\" is not a valid fractal name");
	}
	// ...
}

void			parse_argument(t_everything *everything, char const *arg)
{
	char		**components;

	if (!(arg[0]) || arg[0] == OPT_CHAR_LOCAL)
	{
		error3("empty fractal name in argument \"", arg, "\"");
	}
	components = ft_strsplit(arg, OPT_CHAR_LOCAL);
	if (!components)
	{
		error("ft_strsplit failed");	// when can this happen ?
	}
	parse_components(everything, components);
	ft_strsplit_clear(components);
}

void			process_arguments(t_everything *everything, char **argv)
{
	char const	*arg;

	while ((arg = *(++argv)))
	{
		parse_argument(everything, arg);
	}
	// error if the list remains empty
}
