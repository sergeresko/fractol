/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:31:04 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/23 15:45:02 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		die(void)
{
	exit(EXIT_FAILURE);
}

void			error1(char const *message)
{
	ft_putstr_fd(ERROR_START, STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ERROR_END, STDERR_FILENO);
	die();
}

void			error3(char const *s1, char const *s2, char const *s3)
{
	ft_putstr_fd(ERROR_START, STDERR_FILENO);
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd(s2, STDERR_FILENO);
	ft_putstr_fd(s3, STDERR_FILENO);
	ft_putstr_fd(ERROR_END, STDERR_FILENO);
	die();
}
