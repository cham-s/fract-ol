/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:26 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/29 19:52:26 by cattouma         ###   ########.fr       */
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
	t_color	blk;

	blk.r = 0;
	blk.g = 0;
	blk.b = 0;
	blk.alpha = 0;

	if (keycode == KEY_DOWN)
	{
		draw_set(ti->c->img, &ti->frac);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	}
	else if (keycode == KEY_UP)
	{
		set_background(&blk, ti->c->img);
		mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
		//ti->frac.zoom -= 10;
	}
	/* if (keycode == KEY_LEFT) */
	/* { */
	/* 	t->frac. */
	/* } */
	/* else if (keycode == KEY_RIGHT) */
	/* 	translate(c->coord, 5, 0); */
	/* else if (keycode == KEY_UP) */
	/* 	translate(c->coord, 5, 0); */
	/* else if (keycode == KEY_DOWN) */
	/* 	translate(c->coord, 5, 0); */
}

void	redraw(int key, t_thread_info *ti)
{
	t_color	blk;

	blk.r = 0;
	blk.g = 0;
	blk.b = 0;
	blk.alpha = 0;
	if (key != KEY_ESC && key != KEY_UP && key != KEY_DOWN && key != KEY_LEFT
			&& key != KEY_RIGHT && key != KEY_EQUAL && key != KEY_MIN)
		return ;
	launchfunc(key, ti);
	draw_set(ti->c->img, &ti->frac);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
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
