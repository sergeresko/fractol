/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_positive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:17:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 13:38:28 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	if the string represents a positive number in the range of `int`,
**	return this number; otherwise return zero
*/

int				atoi_positive(char const *str)
{
	int			value;
	char		c;

	value = 0;
	while ((c = *(str++)))
	{
		if (c < '0' || c > '9' || (value = value * 10 + (int)(c - '0')) < 0)
		{
			return (0);
		}
	}
	return (value);
}
