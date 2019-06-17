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

void	_test(t_everything const *everything)
{
	ft_printf("%-20s %4d x %-4d %4d %d\n",
			"(global settings)",
			everything->options[OPT_INDEX_WIDTH],
			everything->options[OPT_INDEX_HEIGHT],
			everything->options[OPT_INDEX_ITER],
			everything->options[OPT_INDEX_COLOR]);
	for (int index = 0; index < everything->window_count; ++index)
	{
		t_window	*window = &(everything->windows[index]);
		ft_printf("%-20s %4d x %-4d %4d %d\n",
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
	t_everything	everything;

	if (ac < 2)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	av = process_global_options(&everything, av);
	process_arguments(&everything, av);
	
	_test(&everything);

	// TODO:
	
	return (EXIT_SUCCESS);
}
