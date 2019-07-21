// TODO: 42 header

#include "fractol.h"
#include <math.h>

void	palette_bernstein(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;
	double		s;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;		// TODO:
		s = 1.0 - t;
		palette[index] = (int)(9.0 * s * t * t * t * 255) << 16
				| (int)(15.0 * s * s * t * t * 255) << 8
				| (int)(8.5 * s * s * s * t * 255);
	}
}

void	palette_blue_brown(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)((1.0 + cos(2.0 * M_PI * 3.0 * t)) * 127.5) << 16
				| (int)((1.0 + cos(2.0 * M_PI * (3.0 * t + 0.1))) * 127.5) << 8
				| (int)((1.0 + cos(2.0 * M_PI * (3.0 * t + 0.2))) * 127.5);
	}
}

void	palette_kaleidoscope(t_win *window)	// TODO:
{
	int		color;
	int		index;

	color = 0x7f00ff;
	index = 0;
	while (index < window->param.iteration_max)
	{
		window->palette[index] = color;
		color += 0x0042f0;//color += 0x000ff0;
		++index;
	}
	window->palette[index - 1] = 0x000000;		// possible because index increments
}

void	palette_greyscale(t_win *window)
{
	int *const	palette = window->palette;
	int const	iteration_max = window->param.iteration_max;
	int			index;
	double		t;

	index = window->param.iteration_max;
	while (index--)
	{
		t = (double)index / iteration_max;
		palette[index] = (int)(t * 255) * (1 << 16 | 1 << 8 | 1 << 0);
	}
}

void	palette_monochrome(t_win *window)
{
	int *const	palette = window->palette;
	int			index;

	index = window->param.iteration_max;
	palette[--index] = 0x000000;		// black
	while (index)
	{
		palette[--index] = 0xffffff;	// white
	}
}
