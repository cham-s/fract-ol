/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:26:35 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/05 17:13:46 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_background(t_color *color, t_image *img)
{
	t_point p;

	p.x = 0;
	p.y = 0;
	while (p.y < HEIGHT)
	{
		while (p.x < WIDTH)
		{
			pixel_put_image_color(img, &p, color);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}

void	put_color(t_frac *f, t_image *img)
{
	if (f->p.x < WIDTH && f->p.y < HEIGHT)
	{
		if (f->p.x >= 0 && f->p.y >= 0)
		{
			if (f->i == f->iter_max)
				pixel_put_image_color(img, &f->p, &f->black);
			else
			{
				f->color.r = (char)(0.16 * f->i + 8) * 230 + 25 + f->co.r;
				f->color.g = (char)(0.13 * f->i + 2) * 230 + 25 + f->co.g;
				f->color.r = (char)(0.034 * f->i + 1) * 230 + 25 + f->co.b;
				f->color.alpha = 0;
				pixel_put_image_color(img, &f->p, &f->color);
			}
		}
	}
}

void	init_mand(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->black.r = 255;
	f->black.g = 255;
	f->black.b = 255;
	f->black.alpha = 255;
	f->color.r = (char)(log(0.16 * f->i + 8) * 230 + 25);
	f->color.g = (char)(sin(0.13 * f->i + 2) * 230 + 25);
	f->color.r = (char)(sin(0.01 * f->i + 1) * 230 + 25);
	f->color.alpha = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.5;
	f->p1.y = -1;
	f->p2.x = 1.0;
	f->p2.y = 1.0;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_julia(t_frac *f)
{
	f->i = 0;
	f->c_r = 0.3;
	f->c_i = -0.0259;
	f->black.r = 0;
	f->black.g = 0;
	f->black.b = 0;
	f->black.alpha = 255;
	f->color.r = (char)(log(0.16 * f->i + 8) * 230 + 25);
	f->color.g = (char)(sin(0.13 * f->i + 2) * 230 + 25);
	f->color.r = (char)(sin(0.01 * f->i + 1) * 230 + 25);
	f->color.alpha = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -3;
	f->p1.y = -1.2;
	f->p2.x = 4;
	f->p2.y = 1.2;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	chose_frac(t_frac *f)
{
	if (f->fract == MAND || f->fract == BURN 
			|| f->fract == BIRD || f->fract == TRI)
	{
		f->c_r = (f->p.x) / f->zoom + f->p1.x;
		f->c_i = (f->p.y) / f->zoom + f->p1.y;
		f->z_r = 0;
		f->z_i = 0;
		f->i = 0;
	}
	else if (f->fract == JULIA)
	{
		f->z_r = f->p.x / f->zoom + f->p1.x;
		f->z_i = f->p.y / f->zoom + f->p1.y;
		f->i = 0;
	}
}

void	choose_z(t_frac *f)
{
	if (f->fract == BURN)
	{
		f->z_r = fabs((f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r);
		f->z_i = fabs(2 * (f->z_i * f->tmp) + f->c_i);
	}
	else if (f->fract == BIRD)
	{
		f->z_r = ((f->z_r * f->z_r) - (f->z_i * f->z_i * 3)) * fabs(f->z_r) + f->c_r;
		f->z_i = ((f->tmp * f->tmp * 3) - (f->z_i * f->z_i)) * fabs(f->z_i) + f->c_i;
	}
	else if (f->fract == TRI)
	{
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = -2 * (f->z_i * f->tmp) + f->c_i;
	}
	else
	{
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2 * (f->z_i * f->tmp) + f->c_i;
	}
}

void	*draw_worker_one(void *p)
{
	t_data_thread	*dt;

	dt = (t_data_thread *)p;
	pthread_mutex_lock(&dt->frac_mutex);
	dt->f->p.x = 0;
	dt->f->p.y = 0;
	while (dt->f->p.x < 225)
	{
		while (dt->f->p.y < HEIGHT)
		{
			chose_frac(dt->f);
			while ((dt->f->z_r * dt->f->z_r) + (dt->f->z_i * dt->f->z_i) < 4 && dt->f->i < dt->f->iter_max)
			{
				dt->f->tmp = dt->f->z_r;
				choose_z(dt->f);
				dt->f->i++;
			}
			put_color(dt->f, dt->img);
			dt->f->p.y++;
		}
		dt->f->p.y = 0;
		dt->f->p.x++;
	}
	pthread_mutex_unlock(&dt->frac_mutex);
	return (NULL);
}

void	*draw_worker_two(void *p)
{
	t_data_thread	*dt;

	dt = (t_data_thread *)p;
	pthread_mutex_lock(&dt->frac_mutex);
	dt->f->p.x = 225;
	dt->f->p.y = 0;
	while (dt->f->p.x < 450)
	{
		while (dt->f->p.y < HEIGHT)
		{
			chose_frac(dt->f);
			while ((dt->f->z_r * dt->f->z_r) + (dt->f->z_i * dt->f->z_i) < 4 && dt->f->i < dt->f->iter_max)
			{
				dt->f->tmp = dt->f->z_r;
				choose_z(dt->f);
				dt->f->i++;
			}
			put_color(dt->f, dt->img);
			dt->f->p.y++;
		}
		dt->f->p.y = 0;
		dt->f->p.x++;
	}
	pthread_mutex_unlock(&dt->frac_mutex);
	return (NULL);
}

void	*draw_worker_three(void *p)
{
	t_data_thread	*dt;

	dt = (t_data_thread *)p;
	pthread_mutex_lock(&dt->frac_mutex);
	dt->f->p.x = 450;
	dt->f->p.y = 0;
	while (dt->f->p.x < 675)
	{
		while (dt->f->p.y < HEIGHT)
		{
			chose_frac(dt->f);
			while ((dt->f->z_r * dt->f->z_r) + (dt->f->z_i * dt->f->z_i) < 4 && dt->f->i < dt->f->iter_max)
			{
				dt->f->tmp = dt->f->z_r;
				choose_z(dt->f);
				dt->f->i++;
			}
			put_color(dt->f, dt->img);
			dt->f->p.y++;
		}
		dt->f->p.y = 0;
		dt->f->p.x++;
	}
	pthread_mutex_unlock(&dt->frac_mutex);
	return (NULL);
}

void	*draw_worker_four(void *p)
{
	t_data_thread	*dt;

	dt = (t_data_thread *)p;
	pthread_mutex_lock(&dt->frac_mutex);
	dt->f->p.x = 675;
	dt->f->p.y = 0;
	while (dt->f->p.x < 900)
	{
		while (dt->f->p.y < HEIGHT)
		{
			chose_frac(dt->f);
			while ((dt->f->z_r * dt->f->z_r) + (dt->f->z_i * dt->f->z_i) < 4 && dt->f->i < dt->f->iter_max)
			{
				dt->f->tmp = dt->f->z_r;
				choose_z(dt->f);
				dt->f->i++;
			}
			put_color(dt->f, dt->img);
			dt->f->p.y++;
		}
		dt->f->p.y = 0;
		dt->f->p.x++;
	}
	pthread_mutex_unlock(&dt->frac_mutex);
	return (NULL);
}

void	launch_thread(pthread_t *t, fn_draw_worker worker, t_data_thread *dt)
{
	int	ret;

	ret = pthread_create(t, NULL, worker, (void *)dt);
	if (ret)
	{
		//check validity
		perror("error creating thread");
		exit(EXIT_FAILURE);
	}
}

void	wait_thread(pthread_t t)
{
	int	ret;

	ret = pthread_join(t, NULL);
	if (ret)
	{
		//check validity
		perror("error creating thread");
		exit(EXIT_FAILURE);
	}
}

void	draw_set(t_image *img, t_frac *f)
{
	t_data_thread		dt;
	pthread_t			draw_threads[NUM_THREADS];
	fn_draw_worker		workers[NUM_THREADS];
	int					i;

	workers[0] = draw_worker_one;
	workers[1] = draw_worker_two;
	workers[2] = draw_worker_three;
	workers[3] = draw_worker_four;

	i = 0;
	dt.img = img;
	dt.f = f;
 	pthread_mutex_init(&dt.frac_mutex, NULL);

	while (i < NUM_THREADS)
	{
		launch_thread(&draw_threads[i], workers[i], &dt);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		wait_thread(draw_threads[i]);
		i++;
	}
	pthread_mutex_destroy(&dt.frac_mutex);
}
