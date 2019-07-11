/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:49:19 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/11 18:50:37 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>			// or "mlx.h" ?
#include "fractol.h"


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
}
