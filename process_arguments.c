/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 20:29:30 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define FRACTAL_TYPE_COUNT	2

void		error(char const *message)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(".\n", STDERR_FILENO);
	die();
}

void		error_ambiguous(char const *name)
{
	ft_putstr_fd("ERROR: Fractal name \"", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\" is ambiguous.\n", STDERR_FILENO);
	die();
}

void		error_invalid(char const *name)
{
	ft_putstr_fd("ERROR: \"", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd("\" is not a valid fractal name.\n", STDERR_FILENO);
	die();
}

void		error_empty(char const *arg)
{
	ft_putstr_fd("ERROR: Empty fractal name in argument \"", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\".\n", STDERR_FILENO);
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
				error_ambiguous(name);
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
		error_invalid(components[0]);
	}
	// ...
}

#define SEPARATOR_CHAR		'.'

void			parse_argument(t_everything *everything, char const *arg)
{
	char		**components;

	if (!(arg[0]) || arg[0] == SEPARATOR_CHAR)
	{
		error_empty(arg);
	}
	components = ft_strsplit(arg, SEPARATOR_CHAR);
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
