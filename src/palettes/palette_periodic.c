// TODO: 42 header

#include "fractol.h"
#include <math.h>

static void	palette_cos(t_win *window, double r, double g, double b)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	palette[--index] = 0xffffff;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)((1.0 + cos(5.0 * M_PI * (t + r))) * 127.5) << 16
				| (int)((1.0 + cos(5.0 * M_PI * (t + g))) * 127.5) << 8
				| (int)((1.0 + cos(5.0 * M_PI * (t + b))) * 127.5);
	}
}

void 		palette_periodic(t_win *window)
{
	static double	phases[][3] = {
		{0.0 / 3.0, 1.0 / 3.0, 2.0 / 3.0},
		{1.0 / 3.0, 0.0 / 3.0, 2.0 / 3.0},
		{2.0 / 3.0, 0.0 / 3.0, 1.0 / 3.0},
		{2.0 / 3.0, 1.0 / 3.0, 0.0 / 3.0},
	};
	double *const	phase = phases[window->color_scheme - 2];

	palette_cos(window, phase[0], phase[1], phase[2]);
}
