/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:15 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:47:51 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>		// mlx_loop
#include "fractol.h"


////////////////////////////////


/*
void	get_args(t_everything *everything, char **av)
{
	av = process_global_options(everything, av);
//	get_args_fractals(everything, av);
}
*/

/*
#define TEST_FORMAT		"%-20s %4d x %-4d %4d %d\n"

void	_test(t_prog const *program)
{
	ft_printf(TEST_FORMAT,
			"(global settings)",
			program->options[OPT_INDEX_WIDTH],
			program->options[OPT_INDEX_HEIGHT],
			program->options[OPT_INDEX_ITER],
			program->options[OPT_INDEX_COLOR]);
	for (int index = 0; index < program->window_count; ++index)
	{
		t_win	*window = &(program->windows[index]);
		ft_printf(TEST_FORMAT,
				window->type->title,
				window->options[OPT_INDEX_WIDTH],
				window->options[OPT_INDEX_HEIGHT],
				window->options[OPT_INDEX_ITER],
				window->options[OPT_INDEX_COLOR]);
	}
}
*/

#include "window.h"		// window_redraw

void			redraw_all(t_prog *program)		// TODO: remove
{
	int			window_index;
	t_win		*window;

	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		window_redraw(window);
	}
}

//

int		main(int ac, char **av)
{
	t_prog		program;

	if (ac < 2)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	av = process_global_options(&program, av);
	process_arguments(&program, av);
	
	start_opencl(&program);
	start_mlx(&program);

	redraw_all(&program);

//	_test(&program);

	mlx_loop(program.mlx_ptr);
	
	return (EXIT_SUCCESS);
}
