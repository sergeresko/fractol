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

int		win_close(void *parameters)
{
	t_win *const	window = parameters;
	t_prog *const	program = window->program;
	int				window_index;

	if (!(program->global_mode))
	{
		window->is_alive = 0;
		mlx_destroy_image(window->program->mlx_ptr, window->img_ptr);
		mlx_destroy_window(window->program->mlx_ptr, window->win_ptr);
		window_index = program->window_count;
		while (window_index--)
		{
			if (program->windows[window_index].is_alive)
			{
				return (0);
			}
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

int		key_press(int keycode, void *parameters)
{
	t_win *const	window = parameters;

	if (keycode == KEY_ESCAPE)
	{
		win_close(parameters);
	}
	else if (keycode == KEY_SHIFT_LEFT)
	{
		window->program->global_mode |= LEFT_SHIFT_PRESSED;
	}
	else if (keycode == KEY_SHIFT_RIGHT)
	{
		window->program->global_mode |= RIGHT_SHIFT_PRESSED;
	}
	else
	{
		// ...
	}
	return (0);
}

int		key_release(int keycode, void *parameters)
{
	t_win *const	window = parameters;

	if (keycode == KEY_SHIFT_LEFT)
	{
		window->program->global_mode &= ~LEFT_SHIFT_PRESSED;
	}
	else if (keycode == KEY_SHIFT_RIGHT)
	{
		window->program->global_mode &= ~RIGHT_SHIFT_PRESSED;
	}
	return (0);
}

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
	int		window_index;
	t_win	*window;
	char	*window_title;
	int		tmp;

	program->mlx_ptr = mlx_init();
	// < TODO: should do this elsewhere
	program->global_mode = 0;
	program->drag_mode = 0;
	// >
	window_index = program->window_count;
	while (window_index--)
	{
		window = &(program->windows[window_index]);
		// < TODO: should do this elsewhere
		window->is_alive = 1;
		window->show_help = 0;
//		window->param.width = window->options[OPT_INDEX_WIDTH];
//		window->param.height = window->options[OPT_INDEX_HEIGHT];
//		window->param.iteration_max = window->options[OPT_INDEX_ITER];
//		window->color = window->options[OPT_INDEX_COLOR];
		// >
		window_title = make_window_title(window_index + 1, window);
		window->win_ptr = mlx_new_window(program->mlx_ptr,
				window->param.width, window->param.height, window_title);
		free(window_title);
		window->img_ptr = mlx_new_image(program->mlx_ptr,
				window->param.width, window->param.height);
		window->img_data = mlx_get_data_addr(window->img_ptr, &tmp, &tmp, &tmp);
		// write to window->img_data ...
		mlx_hook(window->win_ptr, 2, 0, &key_press, window);
		mlx_hook(window->win_ptr, 3, 0, &key_release, window);
		// ...
		mlx_hook(window->win_ptr, 17, 0, &win_close, window);
	}
}