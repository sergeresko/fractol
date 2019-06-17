/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:31:04 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 11:45:09 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void			die(void)
{
	exit(EXIT_FAILURE);
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
