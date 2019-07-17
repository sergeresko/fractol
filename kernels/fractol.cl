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
enum			e_index
{
	RE_0, RE, RE_SQUARED,
	IM_0, IM, IM_SQUARED,
};
*/

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

/*
**
*/

__kernel void		mandelbrot_set(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	/*
	int const		index = get_global_id(0);
	double			val[6];
	int				iter;

	val[RE_0] = p->origin_re + (index % p->width) / p->zoom;
	val[IM_0] = p->origin_im - (index / p->width) / p->zoom;
	val[RE] = 0.0;
	val[IM] = 0.0;
	val[RE_SQUARED] = 0.0;
	val[IM_SQUARED] = 0.0;
	iter = p->iteration_max;
	while (--iter && val[RE_SQUARED] + val[IM_SQUARED] <= 4.0)
	{
		val[IM] = 2.0 * val[RE] * val[IM] + val[IM_0];
		val[RE] = val[RE_SQUARED] - val[IM_SQUARED] + val[RE_0];
		val[RE_SQUARED] = val[RE] * val[RE];
		val[IM_SQUARED] = val[IM] * val[IM];
	}
	img[index] = palette[p->iteration_max - 1 - iter];
	*/

	int const		id = get_global_id(0);
	double const	re0 = p->origin_re + (id % p->width) / p->zoom;
	double const	im0 = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re_squared = re * re;
	double			im_squared = im * im;
	int				iter = p->iteration_max;

	while (--iter && re_squared + im_squared <= 4.0)
	{
		im = 2.0 * re * im + im0;
		re = re_squared - im_squared + re0;
		re_squared = re * re;
		im_squared = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

/*
**
*/

__kernel void		julia_set(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	re0 = p->julia_re0;
	double const	im0 = p->julia_im0;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re_squared = re * re;
	double			im_squared = im * im;
	int				iter = p->iteration_max;

	while (--iter && re_squared + im_squared <= 4.0)
	{
		im = 2.0 * re * im + im0;
		re = re_squared - im_squared + re0;
		re_squared = re * re;
		im_squared = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		multibrot_3(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	re0 = p->origin_re + (id % p->width) / p->zoom;
	double const	im0 = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re_tmp;
	int				iter = p->iteration_max;

	while (--iter && re * re + im * im <= 4.0)
	{
		re_tmp = re * re * re - 3.0 * re * im * im + re0;
		im = 3.0 * re * re * im - im * im * im + im0;
		re = re_tmp;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		multibrot_4(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	re0 = p->origin_re + (id % p->width) / p->zoom;
	double const	im0 = p->origin_im - (id / p->width) / p->zoom;
	double			re = 0.0;
	double			im = 0.0;
	double			re_squared = re * re;
	double			im_squared = im * im;
	double			re_tmp;
	int				iter = p->iteration_max;

	while (--iter && re_squared + im_squared <= 4.0)
	{
		im = 4.0 * re * im * (re_squared - im_squared) + im0;
		re = re_squared * re_squared - 6.0 * re_squared * im_squared + im_squared * im_squared + re0;
		re_squared = re * re;
		im_squared = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

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

__kernel void		newton(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re_squared = re * re;
	double			im_squared = im * im;
	double			absolute = re_squared + im_squared;
	int				iter = p->iteration_max;
	double const	tolerance = 1.0e-6;
	double			roots_re[3] = {1.0, -0.5, -0.5};
	double			roots_im[3] = {0.0, -0.5 * sqrt(3.0), +0.5 * sqrt(3.0)};
	double			re_tmp;
	int				i;

	while (--iter)
	{
		re_tmp = (2.0 * re + (re_squared - im_squared) / (absolute * absolute)) / 3.0;
		im = (2.0 * im - 2.0 * re * im / (absolute * absolute)) / 3.0;
		re = re_tmp;
		i = 3;
		while (i--)
		{
			if (fabs(re - roots_re[i]) < tolerance && fabs(im - roots_im[i]) < tolerance)
			{
				img[id] = palette[p->iteration_max - 1 - iter];
				return ;
			}
		}
		re_squared = re * re;
		im_squared = im * im;
		absolute = re_squared + im_squared;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}

__kernel void		newton_2(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	int const		id = get_global_id(0);
	double const	a_re = p->julia_re0;
	double const	a_im = p->julia_im0;
	double			re = p->origin_re + (id % p->width) / p->zoom;
	double			im = p->origin_im - (id / p->width) / p->zoom;
	double			re_squared = re * re;
	double			im_squared = im * im;
	double			absolute = re_squared + im_squared;
	double			u_re = (re - (re_squared - im_squared) / (absolute * absolute)) / 3.0;
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
		re_squared = re * re;
		im_squared = im * im;
		absolute = re_squared + im_squared;
		u_re = (re - (re_squared - im_squared) / (absolute * absolute)) / 3.0;
		u_im = (im + 2.0 * re * im / (absolute * absolute)) / 3.0;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
}
