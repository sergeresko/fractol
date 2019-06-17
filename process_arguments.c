/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 17:08:09 by syeresko         ###   ########.fr       */
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


////////////////////////////////


/*
**	set each local option of every window to zero
*/

static void		initialize_local_options(t_everything *everything)
{
	int			opt_index;
	int			window_index;
	t_window	*window;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		window_index = everything->window_count;
		while (window_index--)
		{
			window = everything->windows[window_index];
			window->options[opt_index] = 0;
		}
	}
}

/*
**	for each local option of every window, if it is zero,
**	set it to the value of the respective global option
*/

static void		finalize_local_options(t_everything *everything)
{
	int			opt_index;
	int			window_index;
	t_window	*window;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		window_index = everything->window_count;
		while (window_index--)
		{
			window = everything->windows[window_index];
			if (window->options[opt_index] == 0)
			{
				window->options[opt_index] = everything->options[opt_index];
			}
		}
	}
}

static void		initialize_windows(t_everything *everything, char **av)
{
	int			count;

	count = 0;
	while (*(++av))
	{
		++count;
	}
	if (count == 0)
	{
		error("no fractal types specified");
	}
	everything->windows = malloc(count * sizeof(t_window));
	if (!(everything->windows))
	{
		error("malloc failed");		//
	}
	everything->window_count = count;
	everything->active_window_count = count;
}

void			process_arguments(t_everything *everything, char **av)
{
	char const	*arg;

	initialize_windows(everything, av);
	initialize_local_options(everything);
	while ((arg = *(++av)))
	{
		parse_argument(everything, arg);
	}
	finalize_local_options(everything);
}
