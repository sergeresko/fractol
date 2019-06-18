#include <stdlib.h>
#include "fractol.h"


////////////////////////////////


/*
void	get_args(t_everything *everything, char **av)
{
	av = process_global_options(everything, av);
//	get_args_fractals(everything, av);
}
*/

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
	system("leaks -q get >&2");
}

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
	
	_test(&program);

	// TODO:
	
	return (EXIT_SUCCESS);
}
