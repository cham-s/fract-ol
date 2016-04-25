/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:29:19 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:32:22 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	matrix_mult(int mi[3][3], t_point *p)
{
	int i;
	int j;
	int newp[2];

	i = 0;
	j = 0;
	while (i < 2)
	{
		newp[i] = (mi[i][0] * p->x) + (mi[i][1] * p->y) + (mi[i][2] * 1);
		i++;
	}
	p->x = newp[0];
	p->y = newp[1];
}

void	scale(t_coord *co, float x_axis, float y_axis)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = x_axis;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = y_axis;
	matrix[1][2] = 0;
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

void	height(t_coord *co, int n_y)
{
	int v;

	v = 0;
	while (v < co->to_pts)
	{
		co->vert[v]->y -= co->vert[v]->h * n_y;
		v++;
	}
}

void	rotate(t_coord *co, int angle)
{
	int matrix[3][3];
	int v;

	matrix[0][0] = cos(angle);
	matrix[0][1] = -(sin(angle));
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
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
