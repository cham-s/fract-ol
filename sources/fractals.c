/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:26:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/06 22:55:48 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		chose_frac(t_frac *f)
{
	if (f->fract == MAND || f->fract == BURN
		|| f->fract == BIRD || f->fract == TRI)
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
		f->i = 0;
	}
}

static void	choose_z2(t_frac *f)
{
	if (f->fract == TRI)
	{
		f->z_r = (SQRT(f->z_r)) - (SQRT(f->z_i)) + f->c_r;
		f->z_i = -2 * (f->z_i * f->tmp) + f->c_i;
	}
	else if (f->fract == JULIA)
	{
		f->z_r = (SQRT(f->z_r)) - (SQRT(f->z_i)) + f->c_r;
		f->z_i = 2 * (f->z_i * f->tmp) + f->c_i;
	}
	else
	{
		f->z_r = (SQRT(f->z_r)) - (SQRT(f->z_i)) + f->c_r;
		f->z_i = 2 * (f->z_i * f->tmp) + f->c_i;
	}
	/* else */
	/* { */
	/* 	f->z_r = fabs(((SQRT(f->z_r) * f->z_r) - 3 * (SQRT(f->z_i) * f->z_r))) - f->c_i; */
	/* 	f->z_i = 3 * (f->tmp * f->tmp * f->z_i) - (SQRT(f->z_i) * f->z_i) - f->c_r; */
	/* } */
}

void		choose_z(t_frac *f)
{
	if (f->fract == BURN)
	{
		f->z_r = fabs((SQRT(f->z_r)) - (SQRT(f->z_i)) + f->c_r);
		f->z_i = fabs(2 * (f->z_i * f->tmp) + f->c_i);
	}
	else if (f->fract == BIRD)
	{
		f->z_r = ((SQRT(f->z_r)) - (SQRT(f->z_i) * 3)) *
		fabs(f->z_r) + f->c_r;
		f->z_i = ((f->tmp * f->tmp * 3) - (SQRT(f->z_i))) *
		fabs(f->z_i) + f->c_i;
	}
	else
		choose_z2(f);
}
