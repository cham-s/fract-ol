/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:30:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/29 19:52:26 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void usage(void)
{
	ft_putstr_fd("usage:\t", 2);
	ft_putendl_fd("./fractol -[m | j]", 2);
	ft_putendl_fd("help: ", 2);
	ft_putendl_fd("\t-j \tDraw julia set.", 2);
	ft_putendl_fd("\t-m \tDraw mandelbrot set.", 2);
	exit(EXIT_FAILURE);
}

void	choose_set(int frac, t_thread_info *ti)
{
	if (frac == MAND)
	{
		init_mand(&ti->frac);
	}
	else if (frac == JULIA)
		init_julia(&ti->frac);
	draw_set(ti->c->img, &ti->frac);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
}

void	*check_args(void *p)
{
	t_thread_info	*ti;

	ti = (t_thread_info *)p;
	if (ti->ac != 2)
		usage();
	if (!ft_strcmp("-m", ti->f))
		choose_set(MAND, ti);
	else if (!ft_strcmp("-j", ti->f))
	{
		choose_set(JULIA, ti);
	}
	else 
		usage();
	//pthread_exit(0);
	return (NULL);
}
