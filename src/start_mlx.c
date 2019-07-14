/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:49:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/14 16:34:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>			// or "mlx.h" ?
#include "fractol.h"

#define MULTIPLICATION_SIGN	"\xd7"

static char		*make_window_title(int id, t_win const *window)
{
	char *const		id_str = ft_itoa(id);
	char *const		width_str = ft_itoa(window->param.width);
	char *const		height_str = ft_itoa(window->param.height);
	static char		title[80];

	*title = '\0';
	ft_strcat(title, "[");
	ft_strcat(title, id_str);
	ft_strcat(title, "] ");
	ft_strcat(title, window->type->title);
	ft_strcat(title, " (");
	ft_strcat(title, width_str);
	ft_strcat(title, MULTIPLICATION_SIGN);
	ft_strcat(title, height_str);
	ft_strcat(title, ")");
	free(id_str);
	free(width_str);
	free(height_str);
	return (title);
}

static void		start_window(t_prog *program, int window_index)
{
	t_win *const	window = &(program->windows[window_index]);
	char *const		window_title  = make_window_title(window_index + 1, window);
	int				tmp;

	window->win_ptr = mlx_new_window(program->mlx_ptr,
			window->param.width, window->param.height, window_title);
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
/*
#define MENU_WIDTH		190
#define MENU_HEIGHT		440

#define COLOR_BACKGROUND	0x40808080
#define COLOR_BORDER		0x00ffffff

// would be better if this were done in `menu`
static void		create_menu_background(t_prog *program)
{
	int			*data;
	int			tmp;
	int			i;

	program->menu = mlx_new_image(program->mlx_ptr, MENU_WIDTH, MENU_HEIGHT);
	data = mlx_get_data_addr(program->menu, &tmp, &tmp, &tmp);
	i = MENU_WIDTH * MENU_HEIGHT;
	while (i--)
	{
		data[i] = COLOR_BACKGROUND;
	}
	i = MENU_WIDTH;
	while (i--)
	{
		data[i] = COLOR_BORDER;
	}
}
*/
void			start_mlx(t_prog *program)
{
	int			window_index;

	program->mlx_ptr = mlx_init();
	// < TODO: should do this elsewhere (?)
	program->global_mode = 0;
	program->drag_mode = 0;
	// >
	window_index = program->window_count;
	while (window_index--)
	{
		start_window(program, window_index);
	}
}
