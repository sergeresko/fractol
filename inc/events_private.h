/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:11:04 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/17 12:27:14 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_PRIVATE_H
# define EVENTS_PRIVATE_H

# include "actions.h"

/*
**	keyboard
*/

# define KEY_MINUS			27
# define KEY_EQUALS			24
# define KEY_MINUS_NUMPAD	78
# define KEY_PLUS_NUMPAD		69
# define KEY_ESCAPE			53
# define KEY_BRACKET_LEFT	33
# define KEY_BRACKET_RIGHT	30
# define KEY_SHIFT_LEFT		257
# define KEY_SHIFT_RIGHT		258
# define KEY_SPACE			49

# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT		124
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_UP		126

# define KEY_0			29
# define KEY_1				18
# define KEY_2				19
# define KEY_3			20
# define KEY_4			21
# define KEY_0_NUMPAD		82
# define KEY_1_NUMPAD		83
# define KEY_2_NUMPAD		84
# define KEY_3_NUMPAD	85
# define KEY_4_NUMPAD		86

# define KEY_H				4
# define KEY_S				1

/*
**	mouse
*/

# define MOUSE_BUTTON_LEFT	1
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

/*
**
*/

typedef struct	s_bind
{
	int			key;
	t_act		action;
	int			a;
	int			b;
}				t_bind;

void			key_press_toggle(int key, t_win *window);

#endif
