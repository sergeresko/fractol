/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 19:53:36 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

t_type const	*type_info(int index)
{
	static t_type const		info[TYPE_COUNT] = {
		{"Julia set"},
		{"Mandelbrot set"},
	};

	return (&(info[index]));
}

/*
**	for a given name, return the corresponding type index;
**	terminate with error if the name is ambiguous;
**	return -1 if the name is invalid
*/

int			get_type_index_by_title(char const *title)
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


////////////////////////////////


void		parse_components(t_win *window, char **components)
{
	int const	type_index = get_type_index_by_title(*components);
	char		*component;
	int			opt_index;

	if (type_index < 0)
	{
		error3("\"", *components, "\" is not a valid title");
	}
	window->type = type_info(type_index);
	while ((component = *(++components)))
	{
		if ((opt_index = get_opt_index_by_character(component[0])) < 0)
		{
			error3("invalid local option \".", component, "\"");
		}
		set_option(window->options, OPT_CHAR_LOCAL, opt_index, component + 1);
	}
}

void			parse_argument(t_win *window, char const *arg)
{
	char		**components;

	if (!(arg[0]) || arg[0] == OPT_CHAR_LOCAL)
	{
		error3("empty title in argument \"", arg, "\"");
	}
	components = ft_strsplit(arg, OPT_CHAR_LOCAL);
	if (!components)
	{
		error1("ft_strsplit failed");	// when can this happen ?
	}
	parse_components(window, components);
	ft_strsplit_clear(components);
}


////////////////////////////////


static void		initialize_windows(t_prog *program, char **av)
{
	int			count;

	count = 0;
	while (*(++av))
	{
		++count;
	}
	if (count == 0)
	{
		error1("no titles");
	}
	program->windows = malloc(count * sizeof(t_win));
	if (!(program->windows))
	{
		error1("malloc failed");		//
	}
	program->window_count = count;
	program->active_window_count = count;
}

/*
**	set each local option of every window to zero
*/

static void		initialize_local_options(t_prog *program)
{
	int			opt_index;
	int			window_index;
	t_win		*window;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		window_index = program->window_count;
		while (window_index--)
		{
			window = &(program->windows[window_index]);
			window->options[opt_index] = 0;
		}
	}
}

/*
**	for each local option of every window, if it is zero,
**	set it to the value of the respective global option
*/

static void		finalize_local_options(t_prog *program)
{
	int			opt_index;
	int			window_index;
	t_win		*window;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		window_index = program->window_count;
		while (window_index--)
		{
			window = &(program->windows[window_index]);
			if (window->options[opt_index] == 0)
			{
				window->options[opt_index] = program->options[opt_index];
			}
		}
	}
}

void			process_arguments(t_prog *program, char **av)
{
	char const	*arg;
	int			window_index;
	t_win		*window;

	initialize_windows(program, av);
	initialize_local_options(program);
	window_index = 0;
	while ((arg = *(++av)))
	{
		window = &(program->windows[window_index++]);
		parse_argument(window, arg);
	}
	finalize_local_options(program);
}
