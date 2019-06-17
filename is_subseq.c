/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_subseq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:02:39 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 11:54:36 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	tell whether string `sub` is a subsequence of string `full`
*/

int				is_subseq(char const *full, char const *sub)
{
	char		s;
	char		f;

	while ((s = *(sub++)))
	{
		while ((f = *(full++)) != s)
		{
			if (!f)
			{
				return (0);
			}
		}
	}
	return (1);
}
