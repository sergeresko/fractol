/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:33:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/16 16:14:53 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		key_press(int key, void *window);
int		key_release(int key, void *window);
int		mouse_press(int button, int x, int y, void *window);
int		mouse_release(int button, int x, int y, void *window);
int		mouse_move(int x, int y, void *window);
int		win_close(void *window);

#endif
