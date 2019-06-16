/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_subseq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:02:39 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 12:07:08 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	check whether string `sub` is a subsequence of string `full`
*/

int			is_subseq(char const *full, char const *sub)
{
	char	f;
	char	s;

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
