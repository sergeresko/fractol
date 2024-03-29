/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.cl                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 20:13:05 by syeresko          #+#    #+#             */
/*   Updated: 2019/06/21 20:13:15 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	same as in inc/fractol.h
*/

struct			s_param
{
	double		zoom;
	double		origin_re;
	double		origin_im;
	double		var_re;
	double		var_im;
	int			width;
	int			height;
	int			iteration_max;
};

/*
**	===========================================================================
**		Mandelbrot set and its variations
**	===========================================================================
*/

/*
**		(1)		z => z^2 + c
*/

__kernel void		mandelbrot(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + 2.0 * re * im;
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		mandelbrot_j(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->var_re;
	double const	c_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + 2.0 * re * im;
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**		(2)		z => z^3 + c
*/

__kernel void		multibrot3(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + (3.0 * re2 - im2) * im;
		re = c_re + re * (re2 - 3.0 * im2);
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		multibrot3_j(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->var_re;
	double const	c_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + (3.0 * re2 - im2) * im;
		re = c_re + re * (re2 - 3.0 * im2);
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**		(3)		z => z^4 + c
*/

__kernel void		multibrot4(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + (4.0 * re * im * (re2 - im2));
		re = c_re + (re2 * re2) - (6.0 * re2 * im2) + (im2 * im2);
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		multibrot4_j(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->var_re;
	double const	c_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im + (4.0 * re * im * (re2 - im2));
		re = c_re + (re2 * re2) - (6.0 * re2 * im2) + (im2 * im2);
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**		(4)		z => (conj(z))^2 + c
*/

__kernel void		tricorn(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im - 2.0 * re * im;
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		tricorn_j(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->var_re;
	double const	c_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im - 2.0 * re * im;
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**		(5)		z => (|Re z| - i|Im z|)^2 + c
*/

__kernel void		burningship(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im - 2.0 * fabs(re * im);
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		burningship_j(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	c_re = p->var_re;
	double const	c_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	int				iter = p->iteration_max;

	while (--iter && re2 + im2 <= 4.0)
	{
		im = c_im - 2.0 * fabs(re * im);
		re = c_re + re2 - im2;
		re2 = re * re;
		im2 = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	===========================================================================
**		Newton fractals
**	===========================================================================
*/

/*
**		(1)		f(z) = z^3 - 1
*/

/*
**		z => z - f(z) / f'(z)
*/

/*
**		z => z - a * f(z) / f'(z) with variable complex `a`
*/

__kernel void		newton3(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	double const	tolerance = 1.0e-6;
	double const	roots_re[3] = {1.0, -0.5, -0.5};
	double const	roots_im[3] = {0.0, -0.5 * sqrt(3.0), +0.5 * sqrt(3.0)};
	int const		id = get_global_id(0);
	double const	a_re = p->var_re;
	double const	a_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	int				iter = p->iteration_max;

	while (--iter)
	{
		double const	re2 = re * re;
		double const	im2 = im * im;
		double const	abs2 = re2 + im2;
		double const	u_re = (re - (re2 - im2) / (abs2 * abs2)) / 3.0;
		double const	u_im = (im + 2.0 * re * im / (abs2 * abs2)) / 3.0;
		int				i = 3;

		while (i--)
		{
			if (fabs(re - roots_re[i]) < tolerance && fabs(im - roots_im[i]) < tolerance)
			{
				img[id] = palette[p->iteration_max - 1 - iter];
				return ;
			}
		}
		re += -a_re * u_re + a_im * u_im;
		im += -a_re * u_im - a_im * u_re;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	f(z) = sin(z) - 1
*/

__kernel void		newton_sin(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	double const	tolerance = 1.0e-6;
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			denominator = cos(2.0 * re) + cosh(2.0 * im);
	int				iter = p->iteration_max;

	while (--iter)
	{
		double const	t = im - (sinh(2.0 * im) - 2.0 * sin(re) * sinh(im)) / denominator;

		re = re - (sin(2.0 * re) - 2.0 * cos(re) * cosh(im)) / denominator;
		im = t;
		if (fabs(sin(re) * cosh(im) - 1.0) < tolerance && fabs(cos(re) * sinh(im)) < tolerance)
		{
			break ;
		}
		denominator = cos(2.0 * re) + cosh(2.0 * im);
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	f(z) = z^8 + 3 * z^4 - 4
**	http://usefuljs.net/fractals/docs/newtonian_fractals.html
*/

__kernel void		newton_custom(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	double const	tolerance = 1.0e-6;
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	int				iter = p->iteration_max;

	while (--iter)
	{
		double const	re2 = re * re;
		double const	im2 = im * im;
		double const	qu_re = (re2 * re2) - (6.0 * re2 * im2) + (im2 * im2);
		double const	qu_im = 4.0 * re * im * (re2 - im2);
		double const	t = 2.0 * qu_re + 3.0;
		double const	fraction = 25.0 / (t * t + 4.0 * qu_im * qu_im);
		double const	w_re = (1.0 - fraction) * t;
		double const	w_im = (1.0 + fraction) * 2.0 * qu_im;
		double const	c_re = re * (re2 - 3.0 * im2);
		double const	c_im = (im2 - 3.0 * re2) * im;
		double const	k = 0.0625 / ((re2 + im2) * (re2 + im2) * (re2 + im2));
		double const	p_re = k * (c_re * w_re - c_im * w_im);
		double const	p_im = k * (c_re * w_im + c_im * w_re);

		if (fabs(qu_re * qu_re - qu_im * qu_im + 3.0 * qu_re - 4.0) < tolerance
				&& fabs(2.0 * qu_re * qu_im + 3.0 * qu_im) < tolerance)
		{
			break ;
		}
		re = re - p_re;
		im = im - p_im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	===========================================================================
**		Nova fractal
**	===========================================================================
*/

/*
**		z => z - f(z) / f'(z) + c // TODO:
**	NOTE: (a_re, a_im) or (re, im) could be made variable.
*/

__kernel void		newton3_nova(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	double const	tolerance = 1.0e-6;
	int const		id = get_global_id(0);
	double const	a_re = 1.0;
	double const	a_im = 0.0;
	double const	c_re = p->origin_re + (id % p->width) / p->zoom;
	double const	c_im = p->origin_im - (id / p->width) / p->zoom;
	double			re = 1.0;
	double			im = 0.0;
	int				iter = p->iteration_max;

	while (--iter)
	{
		double const	re2 = re * re;
		double const	im2 = im * im;
		double const	abs2 = re2 + im2;
		double const	u_re = (re - (re2 - im2) / (abs2 * abs2)) / 3.0;
		double const	u_im = (im + 2.0 * re * im / (abs2 * abs2)) / 3.0;
		double const	d_re = c_re - (a_re * u_re) + (a_im * u_im);
		double const	d_im = c_im - (a_re * u_im) - (a_im * u_re);

		if (fabs(d_re) < tolerance && fabs(d_im) < tolerance)
		{
			break ;
		}
		re += d_re;
		im += d_im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}
