/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:24:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/29 19:52:27 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_thread_info	ti;
	int				frac_set;

	check_args(ac, av[1], &frac_set);
	ti.c = (t_co *)ft_memalloc(sizeof(t_co));
	choose_set(frac_set, &ti);
	mlx_hook(ti.c->win_ptr, 2, 3, &handler, (void *)&ti);
	mlx_loop(ti.c->mlx_ptr);
	return (0);
}
