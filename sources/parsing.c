/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:30:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/05 17:06:07 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putstr_fd("usage:\t", 2);
	ft_putendl_fd("./fractol -[m | j | b | t | bi]", 2);
	ft_putendl_fd("help: Draw 4 fractals set at max.", 2);
	ft_putendl_fd("\t-j \t\tDraw julia set.", 2);
	ft_putendl_fd("\t-m \t\tDraw mandelbrot set.", 2);
	ft_putendl_fd("\t-b \t\tDraw burning ship set.", 2);
	ft_putendl_fd("\t-bi \t\tDraw bird of prey set.", 2);
	ft_putendl_fd("\t-t \t\tDraw tricorn set.", 2);
	exit(EXIT_FAILURE);
}

void		choose_set(int frac, t_thread_info *ti)
{
	ti->frac.fract = frac;
	if (frac == MAND)
		init_mand(&ti->frac);
	else if (frac == JULIA)
		init_julia(&ti->frac);
	else if (frac == BURN)
		init_burn(&ti->frac);
	else if (frac == TRI)
		init_tri(&ti->frac);
	else if (frac == BIRD)
		init_bird(&ti->frac);
}

static int	fract_set(char *option)
{
	if (!ft_strcmp("-m", option))
		return (MAND);
	else if (!ft_strcmp("-b", option))
		return (BURN);
	else if (!ft_strcmp("-j", option))
		return (JULIA);
	else if (!ft_strcmp("-bi", option))
		return (BIRD);
	else if (!ft_strcmp("-t", option))
		return (TRI);
	else 
		return (0);
}

void		check_args(int ac, char **av, long tab_set[MAX_FRACTALS], int *nf)
{
	int	i;
	int f;

	*nf = 0;
	i = 1;
	f = 0;
	if (ac > MAX_FRACTALS + 1 || ac < 2)
		usage();
	while (i < ac)
	{
		if (!ft_strcmp("-m", av[i]) || !ft_strcmp("-j", av[i]) 
		|| !ft_strcmp("-b", av[i]) || !ft_strcmp("-bi", av[i]) 
		|| !ft_strcmp("-t", av[i]))
		{
			tab_set[f++] = fract_set(av[i]);
			*nf += 1;
			i++;
			continue ;
		}
		else 
			usage();
	}
}
