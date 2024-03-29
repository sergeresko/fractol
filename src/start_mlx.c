/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:49:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 16:00:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "events.h"
#include "libft.h"

#define MULTIPLICATION_SIGN	"\xd7"

static char	*make_window_title(int id, t_win const *window)
{
	char *const	id_str = ft_itoa(id);
	char *const	width_str = ft_itoa(window->options[OPT_INDEX_WIDTH]);
	char *const	height_str = ft_itoa(window->options[OPT_INDEX_HEIGHT]);
	static char	title[80];

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

static void	start_window(t_prog *program, int window_index)
{
	t_win *const	window = &(program->windows[window_index]);
	char *const		title = make_window_title(window_index + 1, window);
	int const		width = window->options[OPT_INDEX_WIDTH];
	int const		height = window->options[OPT_INDEX_HEIGHT];
	int				tmp;

	window->win_ptr = mlx_new_window(program->mlx_ptr, width, height, title);
	window->img_ptr = mlx_new_image(program->mlx_ptr, width, height);
	window->img_data = mlx_get_data_addr(window->img_ptr, &tmp, &tmp, &tmp);
	mlx_hook(window->win_ptr, 2, 0, &key_press, window);
	mlx_hook(window->win_ptr, 3, 0, &key_release, window);
	mlx_hook(window->win_ptr, 4, 0, &mouse_press, window);
	mlx_hook(window->win_ptr, 5, 0, &mouse_release, window);
	mlx_hook(window->win_ptr, 6, 0, &mouse_move, window);
	mlx_hook(window->win_ptr, 17, 0, &win_close, window);
}

void		start_mlx(t_prog *program)
{
	int		window_index;

	program->mlx_ptr = mlx_init();
	window_index = program->window_count;
	while (window_index--)
	{
		start_window(program, window_index);
	}
}
