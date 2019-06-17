/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt_by_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:28:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 17:30:24 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	for a given character return the corresponding option index
**	or -1 if the character does not describe any option
*/

int				get_opt_index_by_character(char c)
{
	int			opt_index;
	t_opt const	*opt;

	opt_index = OPT_COUNT;
	while (opt_index--)
	{
		opt = opt_info(opt_index);
		if (opt->character == c)
		{
			break ;
		}
	}
	return (opt_index);
}
