/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:11:17 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/06 17:16:18 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_co *c)
{
	int		s;

	s = 10;
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 485, WHITE, "RESET: Backspace");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 515, WHITE, "+: Iter +");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 530, WHITE, "-: Iter -");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 550, WHITE, "Arrows: Move");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 570, WHITE, "R : Chg Col R");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 585, WHITE, "G : Chg Col G");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 600, WHITE, "B : Chg Col B");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 620, WHITE, "Scroll +: Z In");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 635, WHITE, "Scroll -: Z Out");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 655, WHITE, "Lock form: L");
	mlx_string_put(c->mlx_ptr, c->win_ptr, s, 675, WHITE, "Toggle Menu: M");
}

void	init_co_img(t_co *c)
{
	t_image	*im;

	c->img = (t_image *)ft_memalloc(sizeof(t_image));
	im = c->img;
	c->mlx_ptr = mlx_init();
	c->img_ptr = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	im->data = mlx_get_data_addr(c->img_ptr, &im->bpp, &im->sizeline,
	&im->endian);
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "fractol");
}
