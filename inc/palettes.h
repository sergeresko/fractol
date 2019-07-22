/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:31:49 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/22 17:09:59 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALETTES_H
# define PALETTES_H

# include "fractol.h"

void	palette_bernstein(t_win *window);
void	palette_periodic(t_win *window);
void	palette_blue_brown(t_win *window);
void	palette_kaleidoscope(t_win *window);
void	palette_greyscale(t_win *window);
void	palette_monochrome(t_win *window);

#endif
