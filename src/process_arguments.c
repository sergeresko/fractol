/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/22 19:33:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

/*
**	TODO: describe
*/

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
//	program->active_window_count = count;
}

/*
**	set each local option of every window to zero
*/

static void		initialize_local_options(t_prog *program)
{
	int			window_index;
	t_win		*window;
	int			opt_index;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		opt_index = OPT_COUNT;
		while (opt_index--)
		{
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
	int *const	global_options = program->options;
	int			window_index;
	t_win		*window;
	int			opt_index;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		window->program = program;		// `window->program` initialization
		opt_index = OPT_COUNT;
		while (opt_index--)
		{
			if (window->options[opt_index] == 0)
			{
				window->options[opt_index] = global_options[opt_index];
			}
		}
	}
}

/*
**	TODO: describe
*/

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
