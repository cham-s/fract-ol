/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/30 17:43:19 by cattouma         ###   ########.fr       */
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

void	launchfunc(int keycode, t_thread_info *ti)
{
	if (keycode == KEY_MIN)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.zoom -= 10 ;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_EQUAL)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.zoom += 10;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	if (keycode == KEY_MIN)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.zoom -= 10 ;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_NUM_PLUS)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.iter_max += 5;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_NUM_MINUS)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.iter_max -= 5;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.p1.x += 0.1;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_RIGHT)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.p1.x -= 0.1;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	if (keycode == KEY_UP)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.p1.y += 0.1;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_DOWN)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		ti->frac.p1.y -= 0.1;
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
}

void	redraw(int key, t_thread_info *ti)
{
	if (key != KEY_ESC && key != KEY_UP && key != KEY_DOWN && key != KEY_LEFT
		&& key != KEY_RIGHT && key != KEY_EQUAL && key != KEY_MIN
		&& key != KEY_NUM_PLUS && key != KEY_NUM_MINUS)
		return ;
	launchfunc(key, ti);
	/* menu(c); */
}

int		handler(int keycode, void *pa)
{
	t_thread_info	*ti;

	ti = (t_thread_info *)pa;
	if (keycode == KEY_ESC)
	{
		exit(EXIT_SUCCESS);
		mlx_destroy_image(ti->c->mlx_ptr, ti->c->img_ptr);
		mlx_destroy_window(ti->c->mlx_ptr, ti->c->win_ptr);
		free(ti->c->img);
		free(ti->c);
	}
	redraw(keycode, ti);
	return (0);
}
