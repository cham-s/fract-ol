/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:30:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/30 18:20:34 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void usage(void)
{
	ft_putstr_fd("usage:\t", 2);
	ft_putendl_fd("./fractol -[m | j | b]", 2);
	ft_putendl_fd("help: ", 2);
	ft_putendl_fd("\t-j \tDraw julia set.", 2);
	ft_putendl_fd("\t-m \tDraw mandelbrot set.", 2);
	ft_putendl_fd("\t-b \tDraw burning ship set.", 2);
	exit(EXIT_FAILURE);
}

void	choose_set(int frac, t_thread_info *ti)
{
	ti->frac.fract = frac;
	if (frac == MAND)
	{
		init_mand(&ti->frac);
	}
	else if (frac == JULIA)
	{
		init_julia(&ti->frac);
	}
	else if (frac == BURN)
	{
		init_mand(&ti->frac);
	}
}

void	check_args(int ac, char *av, int *frac)
{
	if (ac != 2)
		usage();
	if (!ft_strcmp("-m", av))
		*frac = MAND;
	else if (!ft_strcmp("-j", av))
		*frac = JULIA;
	else if (!ft_strcmp("-b", av))
		*frac = BURN;
	else 
		usage();
}
