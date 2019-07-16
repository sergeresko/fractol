/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:36:11 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 15:51:35 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# include "fractol.h"		// t_win
# include <mlx.h>		// or "mlx.h" ?

void		*background_create(void *mlx_ptr, int width, int height);
void		background_display(t_win *window, void *background, int x, int y);

void		help_display(t_win *window, int x, int y);			// window_display_help
void			status_display(t_win *window, int x, int y);	// window_display_status

#endif
