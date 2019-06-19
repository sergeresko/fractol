/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:40:23 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 20:21:57 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include "libft.h"

# define WIDTH_CHAR			'w'
# define WIDTH_MIN			480
# define WIDTH_MAX			4000
# define WIDTH_DEFAULT		800
# define WIDTH_DESCR		"width in pixels"

# define HEIGHT_CHAR		'h'
# define HEIGHT_MIN			360
# define HEIGHT_MAX			2000
# define HEIGHT_DEFAULT		600
# define HEIGHT_DESCR		"height in pixels"

# define ITER_CHAR			'i'
# define ITER_MAX			1000
# define ITER_DEFAULT		100
# define ITER_DESCR			"number of iterations"

# define COLOR_CHAR			'c'
# define COLOR_MAX			5
# define COLOR_DEFAULT		2
# define COLOR_DESCR		"color palette"

typedef struct s_opt		t_opt;
typedef struct s_type		t_type;
typedef struct s_win		t_win;
typedef struct s_prog		t_prog;

# define OPT_INDEX_WIDTH	0
# define OPT_INDEX_HEIGHT	1
# define OPT_INDEX_ITER		2
# define OPT_INDEX_COLOR	3
# define OPT_COUNT			4

struct			s_opt			// t_opt_info
{
	char		character;
	int			min_value;
	int			max_value;
	int			default_value;
	char const	*description;
};

t_opt const		*opt_info(int index);
t_type const	*type_info(int index);

//void			set_global_option(t_everything *everything,
//											t_opt const *opt, char const *arg);
void			set_option(int *options, char opt_prefix,
											int opt_index, char const *arg);
char			**process_global_options(t_prog *program, char **av);
void			parse_argument(t_win *window, char const *arg);
void			process_arguments(t_prog *program, char **av);

# define OPT_CHAR_GLOBAL	'-'
# define OPT_CHAR_LOCAL		'.'

//

# define TYPE_COUNT			2

struct			s_type			// t_type_info
{
	char const	*title;
	// ...
};

struct			s_win
{
	t_prog	*program;	// back-reference
	//
	int		options[OPT_COUNT];		// local options
	//
	t_type const	*type;
	//
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	// ...
};

struct			s_prog
{
	int			options[OPT_COUNT];	// global options
	//
	void		*mlx_ptr;
	//
	t_win		*windows;
	int			window_count;
	int			active_window_count;
};

# define ERROR_START	"error: "
# define ERROR_END		"\n"

void			die(void);
void			error1(char const *message);
void			error3(char const *s1, char const *s2, char const *s3);

void			sprintf_int_left(int value, char *field, int width);
void			sprintf_int_right(int value, char *field, int width);
void			print_usage(void);

#endif
