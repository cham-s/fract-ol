/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:24:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/04 00:05:57 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*start_fractal(void *data)
{
	t_thread_info		ti;
	int					frac_set;

	frac_set = (int )data;

	ti.c = (t_co *)ft_memalloc(sizeof(t_co));
	init_co_img(ti.c);
	choose_set(frac_set, &ti);
	draw_set(ti.c->img, &ti.frac);
	mlx_put_image_to_window(ti.c->mlx_ptr, ti.c->win_ptr, ti.c->img_ptr, 0, 0);
	mlx_hook(ti.c->win_ptr, KeyPress, 3, &handler_key, (void *)&ti);
	mlx_hook(ti.c->win_ptr, MotionNotify, 1L << 6, &handler_julia, (void *)&ti);
	mlx_mouse_hook(ti.c->win_ptr, &handler_mouse, (void *)&ti);
	mlx_loop(ti.c->mlx_ptr);

	return (NULL);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	int					i;
	long				tab_set[MAX_FRACTALS];
	int					nbr_fractal;

	i = 0;
	ft_memset(tab_set, 0, MAX_FRACTALS);
	check_args(ac, av, tab_set, &nbr_fractal);
	while (i < nbr_fractal)
	{
		pid = fork();
		if (pid == -1)
		{
			//check for validity
			perror("Error forking");
			return (-1);
		}
		if (pid == 0)
			start_fractal((void *)tab_set[i]);
		i++;
	} 
	if (pid > 0)
			waitpid(-1, NULL, 0);
	return (EXIT_SUCCESS);
}
