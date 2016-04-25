/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:47:41 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 20:35:07 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	first_case(t_bres *b, t_image *img, t_point *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dx)
	{
		if (p1->x < WIDTH && p1->y < HEIGHT)
			if (p1->x >= 0 && p1->y >= 0)
				pixel_put_image(img, p1);
		i++;
		p1->x += b->x_incr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			p1->y += b->y_incr;
			b->ex += b->dx;
		}
	}
}

void	second_case(t_bres *b, t_image *img, t_point *p1)
{
	int	i;

	i = 0;
	while (i <= b->c_dy)
	{
		if (p1->x < WIDTH && p1->y < HEIGHT)
			if (p1->x >= 0 && p1->y >= 0)
				pixel_put_image(img, p1);
		i++;
		p1->y += b->y_incr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			p1->x += b->x_incr;
			b->ey += b->dy;
		}
	}
}

void	draw_line(t_image *img, t_point p1, t_point p2)
{
	t_bres	b;

	b.ex = abs(p2.x - p1.x);
	b.ey = abs(p2.y - p1.y);
	b.dx = b.ex * 2;
	b.dy = b.ey * 2;
	b.c_dx = b.ex;
	b.c_dy = b.ey;
	b.x_incr = 1;
	b.y_incr = 1;
	if (p1.x > p2.x)
		b.x_incr = -1;
	if (p1.y > p2.y)
		b.y_incr = -1;
	if (b.c_dx >= b.c_dy)
		first_case(&b, img, &p1);
	else if (b.c_dx <= b.c_dy)
		second_case(&b, img, &p1);
}

void	draw_vert(t_coord *co, t_image *img)
{
	int v;

	v = 0;
	while (v < co->to_pts)
	{
		pixel_put_image(img, co->vert[v]);
		v++;
	}
}
