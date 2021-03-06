/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:00:52 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/06 17:12:37 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	redraw2(int keycode, t_thread_info *ti)
{
	if (keycode == KEY_DOWN)
		move_f(&ti->frac, 0, -10);
	if (keycode == KEY_R)
		ti->frac.co.r++;
	if (keycode == KEY_G)
		ti->frac.co.g++;
	if (keycode == KEY_B)
		ti->frac.co.b++;
	if (keycode == KEY_M)
		ti->show = (ti->show == 0 ? 1 : 0);
	if (keycode == KEY_SPACE)
		ti->lock = (ti->lock == 0 ? 1 : 0);
	if (keycode == KEY_BACKSPACE)
	{
		choose_set(ti->frac.fract, ti);
		draw_set(ti->c->img, &ti->frac);
		IMG_TO_WINDOW(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr);
		ti->show = 1;
	}
}

void		redraw(int keycode, t_thread_info *ti)
{
	set_background(&ti->blk, ti->c->img);
	IMG_TO_WINDOW(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr);
	ti->frac.p.x = 0;
	ti->frac.p.y = 0;
	if (keycode == KEY_NUM_PLUS)
		ti->frac.iter_max += 5;
	if (keycode == KEY_NUM_MINUS)
	{
		ti->frac.iter_max -= 5;
		if (ti->frac.iter_max == 0)
			ti->frac.iter_max = 1;
	}
	if (keycode == KEY_LEFT)
		move_f(&ti->frac, 10, 0);
	if (keycode == KEY_RIGHT)
		move_f(&ti->frac, -10, 0);
	if (keycode == KEY_UP)
		move_f(&ti->frac, 0, 10);
	else
		redraw2(keycode, ti);
	draw_set(ti->c->img, &ti->frac);
	IMG_TO_WINDOW(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr);
	if (ti->show)
		menu(ti->c);
}
