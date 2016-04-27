/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:30:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/27 16:00:01 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void usage(void)
{
	ft_putstr_fd("usage:\t", 2);
	ft_putendl_fd("./fractol -[mj]", 2);
	ft_putendl_fd("help: ", 2);
	ft_putendl_fd("\t-j \tDraw julia set.", 2);
	ft_putendl_fd("\t-m \tDraw mandelbrot set.", 2);
	exit(EXIT_FAILURE);
}

void	check_args(int ac, char *f, t_co *c)
{
	t_image	im;

	if (ac != 2)
		usage();
	if (!ft_strcmp("-m", f))
	{
		init_co_img(c, &im);
		mandelbrot(&im);
	}
	else if (!ft_strcmp("-j", f))
	{
		init_co_img(c, &im);
		julia(&im);
	}
	else 
		usage();
}
