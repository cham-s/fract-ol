/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:26:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 20:00:37 by cattouma         ###   ########.fr       */
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

void	mandelbrot(t_image *img)
{
	int iter_max = 50;
	t_point p;
	t_fpoint p1;
	t_fpoint p2;
	double zoom;
	double image_x;
	double image_y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double i;
	double tmp;
	t_color black;
	t_color color;
	black.r = 0;
	black.g = 0;
	black.b = 0;

	p.x = 0;
	p.y = 0;
	p1.x  -2.1;
	p1.y = -1.2;
	p2.x  -0.6;
	p2.y = 1.2;
	zoom = 100;

	image_x = (p2.x - p1.x) * zoom;
	image_y = (p2.y - p1.y) * zoom;

	while (p.x < image_x)
	{
		while (p.y < image_y)
		{
			c_r = p.x / zoom + p1.x;
			c_i = p.y / zoom + p1.y;
			z_r = 0;
			z_i = 0;
			i = 0;

			tmp = z_r;
			z_r = (z_r * z_r) - (z_i * z_i) + c_r;
			z_i = 2 * (z_i * tmp) + c_i;
			i++;
			while (z_r * z_r + z_i < 4 && i < iter_max)
			{
				if (i == iter_max)
					pixel_put_image_color(img, &p, &black);
				else
				{
					color.r = 0;
					color.g = 0;
					color.b = (i * 255) / iter_max;
					pixel_put_image_color(img, &p, &color);
				}
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}
