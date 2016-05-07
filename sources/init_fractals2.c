/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:55:01 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/07 15:29:14 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mand(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_tri(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_bird(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}
