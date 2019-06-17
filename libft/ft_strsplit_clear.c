/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 12:50:45 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 19:57:31 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	Free each element of a NULL-termainated array `tab` as well as `tab` itself.
*/

void	ft_strsplit_clear(char **tab)
{
	char	**ptr;

	ptr = tab;
	while (*ptr != NULL)
	{
		free(*ptr);
		++ptr;
	}
	free(tab);
}
