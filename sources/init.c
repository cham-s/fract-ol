/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/29 19:28:56 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_co *c)
{
	int		s;

	s = WIDTH - 200;
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 10, WHITE, "Esc: Exit");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 25, WHITE, "+: Lvl +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 40, WHITE, "-: Lvl -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 60, WHITE, "Arrows: Move");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 75, WHITE, "F : Front View ");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 95, WHITE, "H : Top View");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 110, WHITE, "P Num 1:R Rot Up");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 125, WHITE, "P Num 2:R Rot Down");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 140, WHITE, "P Num +: Z In");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 155, WHITE, "P Num - : Z Out");
}

void	init_co_img(t_co *c, t_image *im)
{
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline,
	&im->endian);
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "fractol");
	c->img = im;
}
