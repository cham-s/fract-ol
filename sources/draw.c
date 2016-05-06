/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:28:59 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:32:53 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_image(t_image *img, t_point *p)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = 0x00;
	}
}

void	pixel_put_image_color(t_image *img, t_point *p, t_color *col)
{
	if (img->endian == 0)
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = col->r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = col->g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = col->b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = col->alpha;
	}
	else
	{
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 2] = col->b;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 1] = col->g;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 0] = col->r;
		img->data[p->y * img->sizeline + p->x * img->bpp / 8 + 3] = col->alpha;
	}
}

void	put_color(t_frac *f, t_image *img)
{
	t_color	blk;

	blk.r = 0;
	blk.g = 0;
	blk.b = 0;
	if (f->p.x < WIDTH && f->p.y < HEIGHT)
	{
		if (f->p.x >= 0 && f->p.y >= 0)
		{
			if (f->i == f->iter_max)
				pixel_put_image_color(img, &f->p, &blk);
			else
			{
				f->color.r = sin(0.16 * f->i + 8) * 255 / f->iter_max + f->co.r;
				f->color.g = ((sin(0.13 * f->i + 2) * 255 / f->iter_max) * SQRT(5)) + f->co.g;
				f->color.b = (sin(0.02 *f->i + 4) * 255 / f->iter_max) * CUB(5) + f->co.b;
				f->color.alpha = 0;
				pixel_put_image_color(img, &f->p, &f->color);
			}
		}
	}
}
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
