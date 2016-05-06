/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/06 17:16:00 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoomin(t_frac *f, t_point *mp, double factor)
{
	double x;
	double y;

	x = mp->x / f->zoom + f->p1.x;
	y = mp->y / f->zoom + f->p1.y;
	f->zoom *= factor;
	f->p1.x = x - mp->x / f->zoom;
	f->p1.y = y - mp->y / f->zoom;
}

void	zoomout(t_frac *f, t_point *mp, double factor)
{
	double x;
	double y;

	x = mp->x / f->zoom + f->p1.x;
	y = mp->y / f->zoom + f->p1.y;
	f->zoom /= factor;
	f->p1.x = x - mp->x / f->zoom;
	f->p1.y = y - mp->y / f->zoom;
}

void	move_f(t_frac *f, int x, int y)
{
	f->p1.x += (x / f->zoom);
	f->p1.y += (y / f->zoom);
}
