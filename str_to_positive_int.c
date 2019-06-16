/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_positive_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:17:40 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 18:18:18 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	if the string represents a positive number in the range of `int`,
**	return this number; otherwise return 0
*/

int			str_to_positive_int(char const *str)
{
	int		n;
	char	c;

	n = 0;
	while ((c = *(str++)))
	{
		if (c < '0' || c > '9')
		{
			return (0);
		}
		n = n * 10 + (int)(c - '0');
		if (n < 0)
		{
			return (0);
		}
	}
	return (n);
}
