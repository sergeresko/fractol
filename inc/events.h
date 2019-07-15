/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:33:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/15 18:21:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "actions.h"

# include "keycodes.h"		// TODO: incorporate and delete file "keycodes.h"

typedef struct	s_todo
{
	int			key;
	t_act		action;
	int			a;
	int			b;
}				t_todo;

void			key_press_toggle(int key, t_win *window);

#endif
