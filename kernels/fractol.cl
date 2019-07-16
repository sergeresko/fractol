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

enum			e_index
{
	RE_0, RE, RE_SQUARED,
	IM_0, IM, IM_SQUARED,
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

/*
**
*/

__kernel void		mandelbrot_set(
							__global int *img,
							__global int *palette,
							__global struct s_param *p)
{
	/*
	int const		id = get_global_id(0);
	double const	re0 = (id % p->width) / p->zoom - p->origin_re;
	double const	im0 = (p->height - id / p->width) / p->zoom - p->origin_im;
	double			re = 0.0;
	double			im = 0.0;
	double			re_squared = 0.0;
	double			im_squared = 0.0;
	int				iter = p->iteration_max;

	while (--iter && re_squared + im_squared <= 4.0)
	{
		im = 2.0 * re * im + im0;
		re = re_squared - im_squared + re0;
		re_squared = re * re;
		im_squared = im * im;
	}
	img[id] = palette[p->iteration_max - 1 - iter];
	*/
	int const		index = get_global_id(0);
	double			val[6];
	int				iter;

	val[RE_0] = (index % p->width) / p->zoom - p->origin_re;
	val[IM_0] = -(index / p->width) / p->zoom - p->origin_im;
	/*val[IM_0] = (p->height - index / p->width) / p->zoom - p->origin_im;*/
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
	double			re = (id % p->width) / p->zoom - p->origin_re;
	double			im = -(id / p->width) / p->zoom - p->origin_im;
	/*double			im = (p->height - id / p->width) / p->zoom - p->origin_im;*/
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
