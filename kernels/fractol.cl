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
**	z => z^2 + c
*/

__kernel void		mandelbrot_set(
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

/*
**	z => z^2 + c
*/

__kernel void		julia_set(
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
**	z => z^3 + c
*/

__kernel void		multibrot_3(
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

/*
**	z => z^3 + c
*/

__kernel void		julia_3(
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
**	z => z^4 + c
*/

__kernel void		multibrot_4(
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

/*
**	z => z^4 + c
*/

__kernel void		julia_4(
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
**	z => (conj(z))^2 + c
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

/*
**	z => (conj(z))^2 + c
*/

__kernel void		tricorn_julia(
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
**	z => (|Re z| - i|Im z|)^2 + c
*/

__kernel void		burning_ship(
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

/*
**	z => (|Re z| - i|Im z|)^2 + c
*/

__kernel void		burning_ship_julia(
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
__kernel void		negabrot_1(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	re0 = p->origin_re + (id % p->width) / p->zoom;
	double const	im0 = p->origin_im - (id / p->width) / p->zoom;
	double			re = re0;
	double			im = im0;
	double			d;
	int				iter = p->iteration_max;

	while (--iter && (d = re * re + im * im) > 0.001)
	{
		re = re / d + re0;
		im = -im / d + im0;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		negabrot_2(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	re0 = p->origin_re + (id % p->width) / p->zoom;
	double const	im0 = p->origin_im - (id / p->width) / p->zoom;
	double			re = re0;
	double			im = im0;
	double			re_squared = re * re;
	double			im_squared = im * im;
	double			d;
	int				iter = p->iteration_max;

	while (--iter && (d = (re_squared + im_squared) * (re_squared + im_squared)) > 0.00001)
	{
		im = -2.0 * re * im / d + im0;
		re = (re_squared - im_squared) / d + re0;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}
*/

/*
**	p(z) = z^3 - 1
*/

__kernel void		newton(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	double			absolute = re2 + im2;		// TODO: rename
	int				iter = p->iteration_max;
	double const	tolerance = 1.0e-6;
	double			roots_re[3] = {1.0, -0.5, -0.5};
	double			roots_im[3] = {0.0, -0.5 * sqrt(3.0), +0.5 * sqrt(3.0)};
	int				i;

	while (--iter)
	{
		im = (2.0 * im - 2.0 * re * im / (absolute * absolute)) / 3.0;
		re = (2.0 * re + (re2 - im2) / (absolute * absolute)) / 3.0;
		i = 3;
		while (i--)
		{
			if (fabs(re - roots_re[i]) < tolerance && fabs(im - roots_im[i]) < tolerance)
			{
				img[id] = palette[p->iteration_max - 1 - iter];
				return ;
			}
		}
		re2 = re * re;
		im2 = im * im;
		absolute = re2 + im2;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**
*/

__kernel void		newton_var(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	a_re = p->var_re;
	double const	a_im = p->var_im;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	double			absolute = re2 + im2;
	double			u_re = (re - (re2 - im2) / (absolute * absolute)) / 3.0;
	double			u_im = (im + 2.0 * re * im / (absolute * absolute)) / 3.0;
	int				iter = p->iteration_max;
	double const	tolerance = 1.0e-6;
	double			roots_re[3] = {1.0, -0.5, -0.5};
	double			roots_im[3] = {0.0, -0.5 * sqrt(3.0), +0.5 * sqrt(3.0)};
	int				i;

	while (--iter)
	{
		re += -a_re * u_re + a_im * u_im;//re += -u_re + u_im;//re += -2.0 * v1;
		im += -a_re * u_im - a_im * u_re;//im += -u_im - u_re;//im += -2.0 * v2;
		i = 3;
		while (i--)
		{
			if (fabs(re - roots_re[i]) < tolerance && fabs(im - roots_im[i]) < tolerance)
			{
				img[id] = palette[p->iteration_max - 1 - iter];
				return ;
			}
		}
		re2 = re * re;
		im2 = im * im;
		absolute = re2 + im2;
		u_re = (re - (re2 - im2) / (absolute * absolute)) / 3.0;
		u_im = (im + 2.0 * re * im / (absolute * absolute)) / 3.0;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	p(z) = sin(z) - 1
*/

__kernel void		newton_sin(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	double			denominator = cos(2.0 * re) + cosh(2.0 * im);
	int				iter = p->iteration_max;
	double const	tolerance = 1.0e-6;

	while (--iter)
	{
		double t = im - (sinh(2.0 * im) - 2.0 * sin(re) * sinh(im)) / denominator;
		re = re - (sin(2.0 * re) - 2.0 * cos(re) * cosh(im)) / denominator;
		im = t;
		if (fabs(sin(re) * cosh(im) - 1.0) < tolerance && fabs(cos(re) * sinh(im)) < tolerance)
		{
			img[id] = palette[p->iteration_max - 1 - iter];
			return ;
		}
		re2 = re * re;
		im2 = im * im;
		denominator = cos(2.0 * re) + cosh(2.0 * im);
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**	p(z) = z^8 + 3 * z^4 - 4
*/

__kernel void		newton_custom(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re2 = re * re;
	double			im2 = im * im;
	double			qu_re = (re2 * re2) - (6.0 * re2 * im2) + (im2 * im2);
	double			qu_im = 4.0 * re * im * (re2 - im2);

	int				iter = p->iteration_max;
	double const	tolerance = 1.0e-6;

	while (--iter)
	{
		double const	t = 2.0 * qu_re + 3.0;
		double const	fraction = 25.0 / (t * t + 4.0 * qu_im * qu_im);
		double const	w_re = (1.0 - fraction) * t;
		double const	w_im = (1.0 + fraction) * 2.0 * qu_im;
		double const	c_re = re * (re2 - 3.0 * im2);
		double const	c_im = (im2 - 3.0 * re2) * im;
		double const	k = 0.0625 / ((re2 + im2) * (re2 + im2) * (re2 + im2));
		double const	p_re = k * (c_re * w_re - c_im * w_im);
		double const	p_im = k * (c_re * w_im + c_im * w_re);

		re = re - p_re;
		im = im - p_im;
		re2 = re * re;
		im2 = im * im;
		qu_re = (re2 * re2) - (6.0 * re2 * im2) + (im2 * im2);
		qu_im = 4.0 * re * im * (re2 - im2);
		if (fabs(qu_re * qu_re - qu_im * qu_im + 3.0 * qu_re - 4.0) < tolerance
				&& fabs(2.0 * qu_re * qu_im + 3.0 * qu_im) < tolerance)
		{
			img[id] = palette[p->iteration_max - 1 - iter];
			return ;
		}
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}
