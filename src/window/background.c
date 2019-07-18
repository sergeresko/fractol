/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:17:07 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/18 21:38:45 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

#define COLOR_BACKGROUND	0x40808080
#define COLOR_BORDER		0x00eeeeee

void	*background_create(void *mlx_ptr, int width, int height)
{
	void *const	img_ptr = mlx_new_image(mlx_ptr, width, height);
	int			i;
	int *const	data = (int *)mlx_get_data_addr(img_ptr, &i, &i, &i);
	int const	max_index = width * height - 1;

	i = max_index + 1;
	while (i--)
	{
		data[i] = COLOR_BACKGROUND;
	}
	i = width;
	while (i--)
	{
		data[i] = COLOR_BORDER;
		data[max_index - i] = COLOR_BORDER;
	}
	i = max_index + 1;
	while (i -= width)
	{
		data[i] = COLOR_BORDER;
		data[i - 1] = COLOR_BORDER;
	}
	return (img_ptr);
}

void	background_display(t_win *window, void *background, int x, int y)
{
	mlx_put_image_to_window(window->program->mlx_ptr, window->win_ptr,
			background, x, y);
}
