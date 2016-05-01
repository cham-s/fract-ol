/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:26:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/30 19:51:07 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_background(t_color *color, t_image *img)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < HEIGHT)
	{
		while (p.x < WIDTH)
		{
			pixel_put_image_color(img, &p, color);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}

void	put_color(t_frac *f, t_image *img)
{
	if (f->p.x < WIDTH && f->p.y < HEIGHT)
	{
		if (f->p.x >= 0 && f->p.y >= 0)
		{
			if (f->i == f->iter_max)
			{
				pixel_put_image_color(img, &f->p, &f->black);
			}
			else
			{
				f->color.r = 0;
				f->color.g = 0;
				f->color.b = (f->i * 255) / f->iter_max;
				f->color.alpha = 0;
				pixel_put_image_color(img, &f->p, &f->color);
			}
		}
	}
}

void	init_mand(t_frac *f)
{
	f->i = 0;
	f->black.r = 232;
	f->black.g = 232;
	f->black.b = 232;
	f->black.alpha = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.4;
	f->p1.y = -1.25;
	f->p2.x = 0.6;
	f->p2.y = 1.2;
	f->zoom = 300;
	f->image_x = WIDTH;
	f->image_y = HEIGHT;
	f->iter_max = 40;
}

void	init_julia(t_frac *f)
{
	f->i = 0;
	f->black.r = 0;
	f->black.g = 0;
	f->black.b = 0;
	f->black.alpha = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -3;
	f->p1.y = -1.2;
	f->p2.x = 4;
	f->p2.y = 1.2;
	f->zoom = 200;
	f->image_x = WIDTH;
	f->image_y = HEIGHT;
	f->iter_max = 40;
}

void	chose_frac(t_frac *f)
{
	if (f->fract == MAND || f->fract == BURN)
	{
		f->c_r = (f->p.x) / f->zoom + f->p1.x;
		f->c_i = (f->p.y) / f->zoom + f->p1.y;
		f->z_r = 0;
		f->z_i = 0;
		f->i = 0;
	}
	else if (f->fract == JULIA)
	{
		f->z_r = f->p.x / f->zoom + f->p1.x;
		f->z_i = f->p.y / f->zoom + f->p1.y;
		f->c_r = -0.758333;
		f->c_i = -0.0655;
		f->i = 0;
	}
}

void	choose_z(t_frac *f)
{
	if (f->fract == BURN)
	{
		f->z_r = fabs((f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r);
		f->z_i = fabs(2 * (f->z_i * f->tmp) + f->c_i);
	}
	else
	{
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2 * (f->z_i * f->tmp) + f->c_i;
	}
}

void	draw_set(t_image *img, t_frac *f)
{
	while (f->p.x < f->image_x)
	{
		while (f->p.y < f->image_y)
		{
			chose_frac(f);
			while ((f->z_r * f->z_r) + (f->z_i * f->z_i) < 4 && f->i < f->iter_max)
			{
				f->tmp = f->z_r;
				choose_z(f);
				f->i++;
			}
			put_color(f, img);
			f->p.y++;
		}
		f->p.y = 0;
		f->p.x++;
	}
}
