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

typedef struct s_opt		t_opt;
typedef struct s_type		t_type;
typedef struct s_window		t_window;
typedef struct s_everything	t_everything;

# define OPT_INDEX_WIDTH	0
# define OPT_INDEX_HEIGHT	1
# define OPT_INDEX_ITER		2
# define OPT_INDEX_COLOR	3
# define OPT_COUNT			4

struct			s_opt			// t_opt_info
{
	char		character;
	char const	*min_value;
	char const	*max_value;
	char const	*default_value;
	char const	*description;
	int			index;			// needed ?
};

t_opt const		*opt_info(int index);

int				get_opt_index_by_character(char c);
//void			set_global_option(t_everything *everything,
//											t_opt const *opt, char const *arg);
void			set_option(int *options, char opt_prefix,
											int opt_index, char const *arg);
char			**process_global_options(t_everything *everything, char **av);
void			process_arguments(t_everything *everything, char **av);

# define OPT_CHAR_GLOBAL	'-'
# define OPT_CHAR_LOCAL		'.'

//

# define TYPE_COUNT			2

struct			s_type			// t_type_info
{
	char const	*title;
	// ...
};

struct			s_window
{
	t_everything	*everything;	// back-reference
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

struct			s_everything
{
	int			options[OPT_COUNT];	// global options
	//
	void		*mlx_ptr;
	//
	t_window	*windows;
	int			window_count;
	int			active_window_count;
};

int				is_subseq(char const *full, char const *sub);
int				atoi_positive(char const *str);
int				atoi_space(char const *str);

# define ERROR_START	"error: "
# define ERROR_END		"\n"

void			die(void);
void			error1(char const *message);
void			error3(char const *s1, char const *s2, char const *s3);

void			print_usage(void);

#endif
