/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:49:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 21:16:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>			// or "mlx.h" ?
#include "fractol.h"
#include "events.h"		// included only here
#include "libft.h"		// ft_itoa, ft_strcat

#define MULTIPLICATION_SIGN	"\xd7"

static char	*make_window_title(int id, t_win const *window)
{
	char *const	id_str = ft_itoa(id);
	char *const	width_str = ft_itoa(window->param.width);
	char *const	height_str = ft_itoa(window->param.height);
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
	char *const		window_title = make_window_title(window_index + 1, window);
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

void		start_mlx(t_prog *program)
{
	int		window_index;

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
