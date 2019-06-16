#include <stdio.h>		// TODO: remove
#include <string.h>		// TODO: remove

#include <stdlib.h>
#include <mlx.h>		// or do I have to use quotes?

# define KEY_EQUALS			24
# define KEY_MINUS			27
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_UP		126
# define KEY_ESCAPE			53

typedef struct	s_fractol
{
	//
	int		cols;
	int		rows;
	//
	double	a_x;
	double	a_y;
	double	z;		// zoom
	// MLX:
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;		// image data address
}				t_fractol;

void	init_general(t_fractol *fr)
{
	fr->cols = 1024;	// for example
	fr->rows = 512;		// for example
}

void	init_mlx(t_fractol *fr)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, fr->cols, fr->rows, "fract'ol");
	// TODO: window name
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, fr->cols, fr->rows);
	fr->addr = mlx_get_data_addr(fr->img_ptr,
			&bits_per_pixel, &size_line, &endian);
}

void	error_and_exit(char const *message)
{
	fprintf(stderr, "%s\n", message);	// TODO: use `ft_putstr_fd`
	exit(EXIT_FAILURE);
}

void	get_options(t_fractol *fr, int argc, char **argv)
{
	(void)fr;	// TODO:
	if (argc < 2 || argc > 3)
	{
		error_and_exit("usage ...");	// TODO:
	}
	if (strcmp(argv[1], "mandelbrot") == 0)		// TODO: use `ft_strequ`
	{
		// TODO: ...
	}
	else
	{
		error_and_exit("usage ...");	// TODO:
	}
}

int		main(int argc, char **argv)
{
	t_fractol	fr;

	get_options(&fr, argc, argv);
	init_general(&fr);
	init_mlx(&fr);

	system("leaks -q fractol >&2");
	return (EXIT_SUCCESS);
}
