/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:40:23 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/16 19:44:19 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "libft.h"

typedef struct s_opt		t_opt;
typedef struct s_info		t_info;
typedef struct s_fractal	t_fractal;
typedef struct s_everything	t_everything;

# define WIDTH_CHAR		'w'
# define WIDTH_MIN		480
# define WIDTH_MAX		4000
# define WIDTH_DEF		800

# define HEIGHT_CHAR	'h'
# define HEIGHT_MIN		320
# define HEIGHT_MAX		2000
# define HEIGHT_DEF		600

# define ITER_CHAR		'i'
# define ITER_MIN		1
# define ITER_MAX		1000
# define ITER_DEF		100

# define COLOR_CHAR		'c'
# define COLOR_MIN		1
# define COLOR_MAX		5
# define COLOR_DEF		2

# define OPTION_COUNT	4

struct			s_opt
{
	char	character;
	int		min_value;
	int		max_value;
	int		default_value;
	int		*(*addr)(t_everything *);
};

t_opt const		*get_opt(int index);
t_opt const		*get_opt_by_character(char c);
void			set_global_option(t_everything *everything,
											t_opt const *opt, char const *arg);
char			**process_global_options(t_everything *everything, char **av);

//

struct			s_info
{
	char const	*argument;
	char const	*title;
	// ...
};

struct			s_fractal
{
	t_everything	*everything;	// back-reference
	//
	int		width;
	int		height;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	// ...
};

struct			s_everything
{
	// global options:
	int			width;
	int			height;
	int			iterations;
	int			color;
	//
	void		*mlx_ptr;
	int			fractal_count;		// needed ?
	t_fractal	*fractals;
	int			active_fractal_count;
};

int				is_subseq(char const *full, char const *sub);
int				str_to_positive_int(char const *str);
void			die(void);

#endif
