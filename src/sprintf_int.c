/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:39:50 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/19 12:41:04 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	IMPLEMENTATION NOTES:
**
**	The following functions have undefined behavior if `value` is not positive.
**
**	If `value` does not fit into the given width, only least significat digits
**	are printed.
*/

static int		count_digits(int value)
{
	int			count;

	count = 0;
	while (value)
	{
		++count;
		value /= 10;
	}
	return (count);
}

/*
**	print a positive value into a field of given width,
**	aligned to the left and padded with spaces on the right
*/

void			sprintf_int_left(int value, char *field, int width)
{
	int const	length = count_digits(value);

	while (width > length)
	{
		field[--width] = ' ';
	}
	while (width)
	{
		field[--width] = '0' + (char)(value % 10);
		value /= 10;
	}
}

/*
**	print a positive value into a field of given width,
**	aligned to the right and padded with spaces on the left
*/

void			sprintf_int_right(int value, char *field, int width)
{
	while (width && value)
	{
		field[--width] = '0' + (char)(value % 10);
		value /= 10;
	}
	while (width)
	{
		field[--width] = ' ';
	}
}
