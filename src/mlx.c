#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

#define LEFT_SHIFT_PRESSED	(1 << 0)
#define RIGHT_SHIFT_PRESSED	(1 << 1)

#define KEY_MINUS			27
#define KEY_EQUALS			24
#define KEY_MINUS_NUMPAD	78
#define KEY_PLUS_NUMPAD		69
#define KEY_ESCAPE			53
#define KEY_BRACKET_LEFT	33
#define KEY_BRACKET_RIGHT	30
#define KEY_SHIFT_LEFT		257
#define KEY_SHIFT_RIGHT		258
#define KEY_SPACE			49
#define KEY_ARROW_LEFT		123
#define KEY_ARROW_RIGHT		124
#define KEY_ARROW_DOWN		125
#define KEY_ARROW_UP		126
#define KEY_ONE				18
#define KEY_TWO				19
#define KEY_THREE			20
#define KEY_FOUR			21
#define KEY_ONE_NUMPAD		83
#define KEY_TWO_NUMPAD		84
#define KEY_THREE_NUMPAD	85
#define KEY_FOUR_NUMPAD		86
#define KEY_H				4
#define KEY_I				34

#define MOUSE_BUTTON_LEFT	1
#define MOUSE_SCROLL_UP		4
#define MOUSE_SCROLL_DOWN	5
#define STEP_ARROW_MOVE		32
#define STEP_ZOOM			0.1

#define UNUSED				0

typedef void	(*t_func)(t_win *, int, int);

void		apply(t_func action, t_win *window, int a, int b)
{
	t_prog *const	program = window->program;
	int				window_index;

	if (program->global_mode)
	{
		window_index = program->window_count;
		while (window_index--)
		{
			window = &(program->windows[window_index]);
			if (window->is_alive)
			{
				action(window, a, b);
			}
		}
	}
	else
	{
		action(window, a, b);
	}
}

void	action_move(t_win *window, int shift_x, int shift_y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	param->origin_re += shift_x / param->zoom;
	param->origin_im -= shift_y / param->zoom;
	window_redraw(window);
}

void	action_set_palette(t_win *window, int color_scheme, int unused)
{
	(void)unused;
	if (window->color_scheme != color_scheme)
	{
		window->color_scheme = color_scheme;
		fill_palette(window);
		window_redraw(window);
	}
}

void	action_close(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window->is_alive = 0;
	mlx_destroy_image(window->program->mlx_ptr, window->img_ptr);
	mlx_destroy_window(window->program->mlx_ptr, window->win_ptr);
}

void	action_zoom_out(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	if (x < 0 || y < 0)
	{
		x = param->width / 2;
		y = param->height / 2;
	}
	param->origin_re += x / param->zoom * STEP_ZOOM;
	param->origin_im += (param->height - y) / param->zoom * STEP_ZOOM;
	param->zoom /= 1.0 + STEP_ZOOM;
	window_redraw(window);
}

void	action_zoom_in(t_win *window, int x, int y)
{
	t_param *const	param = &(window->param);		// maybe unneeded

	if (x < 0 || y < 0)
	{
		x = param->width / 2;
		y = param->height / 2;
	}
	param->zoom *= 1.0 + STEP_ZOOM;
	param->origin_re -= x / param->zoom * STEP_ZOOM;
	param->origin_im -= (param->height - y) / param->zoom * STEP_ZOOM;
	window_redraw(window);
}

void	action_reset(t_win *window, int unused_1, int unused_2)
{
	(void)unused_1;
	(void)unused_2;
	window_reset(window);		// TODO: incorporate here
	window_redraw(window);
}

////////////////////////////////

int		win_close(void *parameters)
{
	t_win *const	window = parameters;
	t_prog *const	program = window->program;
	int				window_index;

	apply(action_close, window, UNUSED, UNUSED);
	window_index = program->window_count;
	while (window_index--)
	{
		if (program->windows[window_index].is_alive)
		{
			return (0);
		}
	}
	system("leaks -q fractol >&2");		/////////////////////////
	exit(EXIT_SUCCESS);
	return (0);
}

//	key_press
//	esc:
//		destroy_window(window)
//	shift (left):
//		window->program->global_mode |= LEFT_SHIFT_PRESSED;
//	shift (right):
//		window->program->global_mode |= RIGHT_SHIFT_PRESSED;
//	-, - (numpad):
//		zoom_out(window)
//	=, + (numpad):
//		zoom_in(window)
//	[:
//
//	]:
//
//	arrow_up:
//	arrow_right:
//	arrow_down:
//	arrow_left:
//
//	space:
//		reset(window)
//	h:
//	
//	i:
//

int		key_press_arrow(int key, t_win *window)
{
//	int		shift_x;
//	int		shift_y;

	if (key == KEY_ARROW_UP)
	{
		apply(action_move, window, 0, +STEP_ARROW_MOVE);
	}
	else if (key == KEY_ARROW_DOWN)
	{
		apply(action_move, window, 0, -STEP_ARROW_MOVE);
	}
	else if (key == KEY_ARROW_LEFT)
	{
		apply(action_move, window, +STEP_ARROW_MOVE, 0);
	}
	else if (key == KEY_ARROW_RIGHT)
	{
		apply(action_move, window, -STEP_ARROW_MOVE, 0);
	}
	else
	{
		return 0;		// fail
	}
	return 1;			// success
}

int		key_press_digit(int key, t_win *window)
{
	if (key == KEY_ONE || key == KEY_ONE_NUMPAD)
	{
		apply(action_set_palette, window, 1, UNUSED);
	}
	else if (key == KEY_TWO || key == KEY_TWO_NUMPAD)
	{
		apply(action_set_palette, window, 2, UNUSED);
	}
	// TODO:
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press_zoom(int key, t_win *window)
{
	if (key == KEY_MINUS || key == KEY_MINUS_NUMPAD)
	{
		apply(action_zoom_out, window, -1, -1);		// TODO: define
	}
	else if (key == KEY_EQUALS || key == KEY_PLUS_NUMPAD)
	{
		apply(action_zoom_in, window, -1, -1);		// TODO: define
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press_space(int key, t_win *window)
{
	if (key == KEY_SPACE)
	{
		apply(action_reset, window, UNUSED, UNUSED);
	}
	else
	{
		return (0);		// fail
	}
	return (1);			// success
}

int		key_press(int key, void *parameters)
{
	t_win *const	window = parameters;

	if (key == KEY_ESCAPE)
	{
		win_close(parameters);
	}
	else if (key == KEY_SHIFT_LEFT)
	{
		window->program->global_mode |= LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		window->program->global_mode |= RIGHT_SHIFT_PRESSED;
	}
	else
	{
		key_press_arrow(key, window) || key_press_digit(key, window) || key_press_zoom(key, window) || key_press_space(key, window);
		// ...
	}
	return (0);
}

int		key_release(int key, void *parameters)
{
	t_win *const	window = parameters;

	if (key == KEY_SHIFT_LEFT)
	{
		window->program->global_mode &= ~LEFT_SHIFT_PRESSED;
	}
	else if (key == KEY_SHIFT_RIGHT)
	{
		window->program->global_mode &= ~RIGHT_SHIFT_PRESSED;
	}
	return (0);
}

////////////////

int		mouse_press(int button, int x, int y, void *parameters)
{
	t_win *const	window = parameters;

	if (button == MOUSE_BUTTON_LEFT)
	{
		if (!(window->program->drag_mode))
		{
			window->program->drag_x = x;
			window->program->drag_y = y;
		}
		window->program->drag_mode = 1;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		apply(action_zoom_out, window, x, y);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		apply(action_zoom_in, window, x, y);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *parameters)
{
	t_win *const	window = parameters;

	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
	{
		window->program->drag_mode = 0;
	}
	return (0);
}

int		mouse_move(int x, int y, void *parameters)
{
	t_win *const	window = parameters;

	if (x < 0 || x >= window->param.width
			|| y < 0 || y >= window->param.height)
	{
//		return (0);
	}
	// <
	int		id;
	id = window->program->window_count;
	while (window != &(window->program->windows[--id]))
		;
	ft_printf("mouse_move (window %d)    x: %4d    y: %4d\n", id + 1, x, y);
	// >
	if (window->program->drag_mode)
	{
		apply(action_move, window, x - window->program->drag_x, y - window->program->drag_y);
		window->program->drag_x = x;
		window->program->drag_y = y;
	}
	return (0);
}

////////////////////////////////
/*
#define MULTIPLICATION_SIGN	"\xd7"

static char		*make_window_title(int id, t_win const *window)
{
	char *const	id_str = ft_itoa(id);
	char *const	width_str = ft_itoa(window->param.width);
	char *const	height_str = ft_itoa(window->param.height);
	char		*tmp[2];

	tmp[0] = ft_strjoin("[", id_str);
	tmp[1] = ft_strjoin(tmp[0], "] ");
	free(tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], window->type->title);
	free(tmp[1]);
	tmp[1] = ft_strjoin(tmp[0], " (");
	free(tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], width_str);
	free(tmp[1]);
	tmp[1] = ft_strjoin(tmp[0], MULTIPLICATION_SIGN);
	free(tmp[0]);
	tmp[0] = ft_strjoin(tmp[1], height_str);
	free(tmp[1]);
	tmp[1] = ft_strjoin(tmp[0], ")");
	free(tmp[0]);
	free(id_str);
	free(width_str);
	free(height_str);
	return (tmp[1]);
}

void			start_mlx(t_prog *program)
{
	int			window_index;
	t_win		*window;
	char		*window_title;
	int			tmp;

	program->mlx_ptr = mlx_init();
	// < TODO: should do this elsewhere (?)
	program->global_mode = 0;
	program->drag_mode = 0;
	// >
	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		window_title = make_window_title(window_index + 1, window);
		window->win_ptr = mlx_new_window(program->mlx_ptr,
				window->param.width, window->param.height, window_title);
		free(window_title);
		window->img_ptr = mlx_new_image(program->mlx_ptr,
				window->param.width, window->param.height);
		window->img_data = mlx_get_data_addr(window->img_ptr, &tmp, &tmp, &tmp);
		mlx_hook(window->win_ptr, 2, 0, &key_press, window);
		mlx_hook(window->win_ptr, 3, 0, &key_release, window);
		mlx_hook(window->win_ptr, 4, 0, &mouse_press, window);
		mlx_hook(window->win_ptr, 5, 0, &mouse_release, window);
		mlx_hook(window->win_ptr, 6, 0, &mouse_move, window);
		mlx_hook(window->win_ptr, 17, 0, &win_close, window);
	}
}*/
