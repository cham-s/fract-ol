/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 20:38:10 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_co *c)
{
	int		s;
	char	*x;
	char	*y;

	x = ft_itoa(c->coord->vert[0]->x);
	y = ft_itoa(c->coord->vert[0]->y);
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
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 10, WHITE, "origin x: ");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 120, 10, WHITE, x);
	mlx_string_put(c->mlx_ptr, c->win_ptr, 15, 25, WHITE, "origin y: ");
	mlx_string_put(c->mlx_ptr, c->win_ptr, 120, 25, WHITE, y);
	free(x);
	free(y);
}

void	init_co_img(t_co *c, t_image *im)
{
	c->bg_color.r = 125;
	c->bg_color.g = 25;
	c->bg_color.b = 53;
	c->bg_color.alpha = 0;
	c->line_color = WHITE;
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline,
	&im->endian);
	im->img_color = mlx_get_color_value(c->mlx_ptr, c->line_color);
	c->img = im;
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "fractol");
	set_background(&c->bg_color, c->img);
	mandelbrot(im);
}
