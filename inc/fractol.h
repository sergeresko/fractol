/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <syeresko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:40:23 by syeresko          #+#    #+#             */
/*   Updated: 2019/07/17 14:58:28 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//# include <mlx.h>

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

//# include <unistd.h>
//# include "libft.h"

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
typedef struct s_param		t_param;

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

# define OPT_PREFIX_GLOBAL	'-'
# define OPT_PREFIX_LOCAL	'.'

//

# define TYPE_COUNT			7

struct			s_type			// t_type_info
{
	char const	*title;
	char const	*cl_kernel_name;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	int			is_variable;
	// ...
};

struct			s_param
{
	double		zoom;
	double		origin_re;
	double		origin_im;
	double		julia_re0;
	double		julia_im0;
	int			width;
	int			height;
	int			iteration_max;
};

struct			s_win
{
	t_prog			*program;	// back-reference
	//
	int				options[OPT_COUNT];		// local options
	//
	t_type const	*type;
	//
	t_param			param;
	int				color_scheme;
	int				palette[ITER_MAX];
	// OpenCL:
	size_t			cl_global_size;		// .param.width * .param.height
	cl_mem			cl_img;				// CL buffers for:	.img_data
	cl_mem			cl_palette;			//					.palette
	cl_mem			cl_param;			//					.param
	cl_kernel		cl_kernel;
	// MiniLibX:
	void			*win_ptr;
	void			*img_ptr;
	void			*img_data;
	//
	int				is_alive;
	int				is_help_shown;
	int				is_status_shown;
	//
	int				is_fixed;
};

struct			s_prog
{
	int					options[OPT_COUNT];		// global options, TODO: remove
	t_win				*windows;
	int					window_count;
//	int					active_window_count;	// needed?
	// OpenCL:
	cl_context			cl_context;
	cl_command_queue	cl_commands;
	cl_program			cl_program;
	// MiniLibX:
	void				*mlx_ptr;
	int					global_mode;
	int					drag_mode;
	int					drag_x;
	int					drag_y;
	//
	double				julia_re;
	double				julia_im;
};

# define ERROR_START	"error: "
# define ERROR_END		"\n"

void			error1(char const *message);
void			error3(char const *s1, char const *s2, char const *s3);

void			sprintf_int_left(int value, char *field, int width);
void			sprintf_int_right(int value, char *field, int width);
void			print_usage(void);

void			fill_palette(t_win *window);

//void			init_parameters(t_prog *program);

void			start_mlx(t_prog *program);
void			start_opencl(t_prog *program);

void			window_reset(t_win *window);	// TODO: incorporate in action_reset

void			redraw_all(t_prog *program);

#endif
