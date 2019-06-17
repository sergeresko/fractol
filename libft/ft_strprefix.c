/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:25:03 by syeresko          #+#    #+#             */
/*   Updated: 2019/03/30 12:27:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Equivalent to strncmp(str, prefix, strlen(prefix)) == 0, i.e.
**	returns 1 if str begins with prefix or 0 otherwise.
*/

int		ft_strprefix(char const *str, char const *prefix)
{
	while (*prefix)
		if (*(str++) != *(prefix++))
			return (0);
	return (1);
}
