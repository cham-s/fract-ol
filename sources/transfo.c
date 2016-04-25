/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:41:28 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:33:49 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rot(t_coord *co, int d, int g, int h)
{
	int v;
	int x;
	int y;
	int ox;
	int oy;

	v = 0;
	x = 0;
	y = 0;
	ox = co->vert[v]->x;
	oy = co->vert[v]->y;
	while (y < co->y_point)
	{
		while (x < co->x_point)
		{
			co->vert[v]->x = ((x * g) - (y * g)) + ox;
			co->vert[v]->y = ((x * g) + (y * g)) / d + oy
			- (co->vert[v]->h * h);
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	zoom(t_coord *co, int g, int h, int d)
{
	int v;
	int x;
	int y;
	int ox;
	int oy;

	v = 0;
	x = 0;
	y = 0;
	ox = co->vert[v]->x;
	oy = co->vert[v]->y;
	while (y < co->y_point)
	{
		while (x < co->x_point)
		{
			co->vert[v]->x = ((x * g) - (y * g)) + ox;
			co->vert[v]->y = ((x * g) + (y * g)) / d + oy
			- (co->vert[v]->h * h);
			v++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	translate(t_coord *co, int x_axis, int y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = x_axis;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = y_axis;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	v = 0;
	while (v < co->to_pts)
	{
		matrix_mult(matrix, co->vert[v]);
		v++;
	}
}
