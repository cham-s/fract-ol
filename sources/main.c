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
	t_co			c;
	t_image 		im;
	//pthread_t		threads[NUM_THREADS];
	//int				rc;
	t_thread_info	ti;

	init_co_img(&c, &im);
	ti.ac = ac;
	ti.f = av[1];
	ti.c = &c;
	check_args((void *)&ti);
	/* rc = pthread_create(&threads[0], NULL, check_args, &ti); */
	/* if (rc) */
	/* { */
	/* 	ft_putendl_fd("error: from pthread_create call in the thread #1", 2); */
	/* 	exit (-1); */
	/* } */
	/* rc = pthread_create(&threads[1], NULL, check_args, &ti); */
	/* if (rc) */
	/* { */
	/* 	ft_putendl_fd("error: from pthread_create call in the thread #1"); */
	/* 	exit (-1); */
	/* } */
	//menu(&c);
	mlx_hook(c.win_ptr, 2, 3, &handler, (void *)&ti);
	mlx_loop(c.mlx_ptr);
	//pthread_exit(NULL);
	return (0);
}
