/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:06 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:32:23 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "fractol.h"
#include "libft.h"		// ft_memalloc

/*
**	TODO: describe
*/

static void	allocate_windows(t_prog *program, char **av)
{
	int		count;

	count = 0;
	while (*(++av))
	{
		++count;
	}
	if (count == 0)
	{
		error1("no titles");
	}
	program->windows = ft_memalloc(count * sizeof(t_win));		// zeroed
	if (!(program->windows))
	{
		error1("malloc failed");		// ?
	}
	program->window_count = count;
}

/*
**	for each local option of the window, if it is zero,
**	set it to the value of the respective global option
*/

static void	finalize_local_options(t_win *window)
{
	int *const	global_options = window->program->options;
	int			opt_index;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		if (window->options[opt_index] == 0)
		{
			window->options[opt_index] = global_options[opt_index];
		}
	}
}

/*
**	TODO: describe
*/

void		process_arguments(t_prog *program, char **av)
{
	char const	*arg;
	int			window_index;
	t_win		*window;

	allocate_windows(program, av);
	window_index = 0;
	while ((arg = *(++av)))
	{
		window = &(program->windows[window_index++]);
		window->program = program;		// `window->program` initialization
		parse_argument(window, arg);
		finalize_local_options(window);
		window_reset(window);
		window->is_alive = 1;
		window->is_help_shown = 0;
		window->is_status_shown = 0;
		window->is_fixed = 0;
	}
}
