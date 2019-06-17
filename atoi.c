/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:17:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 13:38:28 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	if the string represents a positive number in the range of `int`,
**	return this number; otherwise return 0
*/

int				atoi_positive(char const *str)
{
	int			n;
	char		c;

	n = 0;
	while ((c = *(str++)))
	{
		if (c < '0' || c > '9' || (n = n * 10 + (int)(c - '0')) < 0)
		{
			return (0);
		}
	}
	return (n);
}

/*
**	return the positive number represented by a string (probably padded with
**	spaces on either side); the result is undefined if the string is not valid
*/

int				atoi_space(char const *str)
{
	int			n;
	char		c;

	while (*str == ' ')
	{
		++str;
	}
	n = 0;
	while ((c = *(str++)) && c != ' ')
	{
		n = n * 10 + (int)(c - '0');
	}
	return (n);
}
