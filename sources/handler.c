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

void	zoomin(t_frac *f, t_point *mp, double factor)
{
	double x;
	double y;

	x = mp->x / f->zoom + f->p1.x;
	y = mp->y / f->zoom + f->p1.y;
	f->zoom *= factor;
	f->p1.x = x - (WIDTH / f->zoom) / 2;
	f->p1.y = y - (HEIGHT / f->zoom) / 2;
}

void	zoomout(t_frac *f, t_point *mp, double factor)
{
	double x;
	double y;

	x = mp->x / f->zoom + f->p1.x;
	y = mp->y / f->zoom + f->p1.y;
	f->zoom /= factor;
	f->p1.x = x - (WIDTH / f->zoom) / 2;
	f->p1.y = y - (HEIGHT / f->zoom) / 2;
}

void	move_f(t_frac *f, t_point *mp)
{
	f->p1.x += (mp->x / f->zoom);
	f->p1.y += (mp->y/ f->zoom);
}

void	launchfunc(int keycode, t_thread_info *ti, t_point *mp)
{
	t_color blk;

	blk.r = 0;
	blk.g = 0;
	blk.b = 0;
	blk.alpha = 0;
	set_background(&blk, ti->c->img);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	if (keycode == WHEEL_DOWN)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		zoomout(&ti->frac, mp, 1.5);
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == WHEEL_UP)
	{
		ti->frac.p.x = 0;
		ti->frac.p.y = 0;
		zoomin(&ti->frac, mp, 1.5);
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
	else if (keycode == KEY_UP)
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

void	redraw(int key, t_thread_info *ti, t_point *mp)
{
	if (key != KEY_ESC && key != KEY_UP && key != KEY_DOWN && key != KEY_LEFT
		&& key != KEY_RIGHT && key != KEY_EQUAL && key != KEY_MIN
		&& key != KEY_NUM_PLUS && key != KEY_NUM_MINUS
		&&  key != WHEEL_UP && key != WHEEL_DOWN)
		return ;
	launchfunc(key, ti, mp);
	/* menu(c); */
}

int		handler_key(int keycode, void *pa)
{
	t_thread_info	*ti;
	t_point			mp;

	mp.x = 0;
	mp.y = 0;
	ti = (t_thread_info *)pa;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(ti->c->mlx_ptr, ti->c->img_ptr);
		mlx_destroy_window(ti->c->mlx_ptr, ti->c->win_ptr);
		free(ti->c->img);
		free(ti->c);
		exit(EXIT_SUCCESS);
	}
	redraw(keycode, ti, &mp);
	return (0);
}

int		handler_mouse(int b,int x, int y, void *p)
{
	t_thread_info	*ti;
	t_point			mp;

	if (y > 0)
	{
		ti = (t_thread_info *)p;
		mp.x = x;
		mp.y = y;
		redraw(b, ti, &mp);
	}
	return (0);
}
