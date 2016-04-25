/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:24:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:30:09 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_co	c;
	t_image	im;

	check_args(ac, av[1]);
	c.gap = 10;
	c.c_height = 10;
	c.div = 2;
	stock_coord(av[1], &c);
	init_co_img(&c, &im);
	mlx_put_image_to_window(c.mlx_ptr, c.win_ptr, c.img_ptr, 0, 0);
	menu(&c);
	mlx_hook(c.win_ptr, 2, 3, &handler, (void*)&c);
	mlx_loop(c.mlx_ptr);
	return (0);
}
