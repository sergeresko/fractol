/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:40:23 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/17 13:18:10 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "libft.h"

typedef struct s_opt		t_opt;
typedef struct s_info		t_info;
typedef struct s_window		t_window;
typedef struct s_everything	t_everything;

# define OPT_INDEX_WIDTH	0
# define OPT_INDEX_HEIGHT	1
# define OPT_INDEX_ITER		2
# define OPT_INDEX_COLOR	3
# define OPT_COUNT			4

typedef int					t_options[OPT_COUNT];

struct			s_opt
{
	char	character;
	int		min_value;
	int		max_value;
	int		default_value;
	size_t	index;
};

t_opt const		*opt_info(size_t index);
int				opt_get(int const *options, t_opt const *opt);
void			opt_set(int *options, t_opt const *opt, int value);

t_opt const		*get_opt_by_character(char c);
void			set_global_option(t_everything *everything,
											t_opt const *opt, char const *arg);
char			**process_global_options(t_everything *everything, char **av);

# define OPT_CHAR_GLOBAL	'-'
# define OPT_CHAR_LOCAL		'.'

//

struct			s_info
{
	char const	*argument;
	char const	*title;
	// ...
};

struct			s_window
{
	t_everything	*everything;	// back-reference
	//
	t_options	options;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	// ...
};

struct			s_everything
{
	t_options	options;
	//
	void		*mlx_ptr;
	int			fractal_count;		// needed ?
	t_window	*windows;
	int			active_fractal_count;
};

int				is_subseq(char const *full, char const *sub);
int				str_to_positive_int(char const *str);

# define ERROR_START	"error: "
# define ERROR_END		"\n"

void			die(void);
void			error3(char const *s1, char const *s2, char const *s3);

#endif
