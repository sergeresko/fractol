/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt_by_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:28:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 11:56:43 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*get_opt_by_character(char c)
{
	t_opt const	*opt;
	int			i;

	i = 0;
	while (i < OPTION_COUNT)
	{
		if ((opt = get_opt(i++))->character == c)
		{
			return (opt);
		}
	}
	return (NULL);
}
