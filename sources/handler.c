/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/27 15:58:47 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	laun2(int *keycode, t_co *c) */
/* { */
/* 	if (*keycode == KEY_UP) */
/* 		translate(c->coord, 0, -5); */
/* 	else if (*keycode == KEY_DOWN) */
/* 		translate(c->coord, 0, 5); */
/* 	else if (*keycode == KEY_NUM_1) */
/* 		rot(c->coord, c->div += 1, c->gap, c->c_height); */
/* 	else if (*keycode == KEY_NUM_2) */
/* 	{ */
/* 		c->div--; */
/* 		if (c->div == 0) */
/* 			c->div = 1; */
/* 		rot(c->coord, c->div, c->gap, c->c_height); */
/* 	} */
/* 	else if (*keycode == KEY_F) */
/* 		rot(c->coord, 1000, c->gap, c->c_height); */
/* 	else if (*keycode == KEY_H) */
/* 		rot(c->coord, 1, c->gap, c->c_height); */
/* } */

/* void	launchfunc(int keycode, t_co *c) */
/* { */
/* 	if (keycode == KEY_EQUAL) */
/* 		height(c->coord, 2); */
/* 	else if (keycode == KEY_MIN) */
/* 		height(c->coord, -2); */
/* 	else if (keycode == KEY_NUM_MINUS) */
/* 	{ */
/* 		c->gap -= 2; */
/* 		if (c->gap == 0 || c->gap < 0) */
/* 			c->gap = 1; */
/* 		c->c_height -= 2; */
/* 		if (c->c_height == 0 || c->c_height < 0) */
/* 			c->c_height = 1; */
/* 		zoom(c->coord, c->gap, c->c_height, c->div); */
/* 	} */
/* 	else if (keycode == KEY_NUM_PLUS) */
/* 		zoom(c->coord, c->gap += 2, c->c_height += 2, c->div); */
/* 	else if (keycode == KEY_LEFT) */
/* 		translate(c->coord, -5, 0); */
/* 	else if (keycode == KEY_RIGHT) */
/* 		translate(c->coord, 5, 0); */
/* 	else */
/* 		laun2(&keycode, c); */
/* } */
/*  */
/* void	redraw(t_co *c, int key) */
/* { */
/* 	if (key != KEY_LEFT && key != KEY_RIGHT && key != KEY_UP && key != KEY_DOWN */
/* 		&& key != KEY_MIN */
/* 		&& key != KEY_NUM_PLUS && key != KEY_NUM_MINUS && */
/* 		key != KEY_EQUAL && key != KEY_NUM_1 && key != KEY_NUM_2 */
/* 		&& key != KEY_F && key != KEY_H) */
/* 		return ; */
/* 	set_background(&c->bg_color, c->img); */
/* 	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0); */
/* 	c->img->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color); */
/* 	launchfunc(key, c); */
/* 	//print_point(c->coord, c->img); */
/* 	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->img_ptr, 0, 0); */
/* 	menu(c); */
/* } */

int		handler(int keycode, void *pa)
{
	//
	(void)pa;
	if (keycode == KEY_ESC)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
