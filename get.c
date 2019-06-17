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

void	_test(t_everything const *everything, char **av)
{
	ft_printf("Global settings:\n");
	ft_printf("%d x %d (%d iterations, palette %d)\n",
			everything->options[OPT_INDEX_WIDTH],
			everything->options[OPT_INDEX_HEIGHT],
			everything->options[OPT_INDEX_ITER],
			everything->options[OPT_INDEX_COLOR]);
	ft_printf("The last processed argument is \"%s\".\n", *av);
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
	
	_test(&everything, av);

	// TODO:
	
	return (EXIT_SUCCESS);
}
