/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt_by_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:28:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 12:43:42 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_opt const		*get_opt_by_character(char c)
{
	size_t		i;
	t_opt const	*opt;

	i = 0;
	while ((opt = opt_info(i++)))
	{
		if (opt->character == c)
		{
			return (opt);
		}
	}
	return (NULL);
}
