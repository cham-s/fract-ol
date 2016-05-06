/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:01:09 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/06 23:43:51 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*draw_worker(void *p)
{
	t_data_thread	*dt;

	dt = (t_data_thread *)p;
	pthread_mutex_lock(&dt->frac_mutex);
	dt->f->p.y = 0;
	while (dt->f->p.x < dt->end)
	{
		while (dt->f->p.y < HEIGHT)
		{
			chose_frac(dt->f);
			while ((dt->f->z_r * dt->f->z_r) + (SQRT(dt->f->z_i)) <
					4 && dt->f->i < dt->f->iter_max)
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

static void	launch_thread(pthread_t *t, void *(worker)(void *p),
						t_data_thread *dt)
{
	int	ret;

	ret = pthread_create(t, NULL, worker, (void *)dt);
	if (ret)
	{
		perror("error creating thread");
		exit(EXIT_FAILURE);
	}
}

static void	wait_thread(pthread_t t)
{
	int	ret;

	ret = pthread_join(t, NULL);
	if (ret)
	{
		perror("error joining thread");
		exit(EXIT_FAILURE);
	}
}

static void	init_starts_ends(int starts[NUM_THREADS], int ends[NUM_THREADS])
{
	int i;
	int actual_step;

	i = 0;
	actual_step = 0;
	while (i < NUM_THREADS)
	{
		starts[i] = actual_step;
		ends[i] = actual_step + STEP;
		actual_step += STEP;
		i++;
	}
}

void		draw_set(t_image *img, t_frac *f)
{
	t_data_thread		dt;
	pthread_t			draw_threads[NUM_THREADS];
	int					i;
	int					starts[NUM_THREADS];
	int					ends[NUM_THREADS];

	init_starts_ends(starts, ends);
	i = 0;
	dt.img = img;
	dt.f = f;
	pthread_mutex_init(&dt.frac_mutex, NULL);
	while (i < NUM_THREADS)
	{
		dt.start = starts[i];
		dt.f->p.x = dt.start;
		dt.end = ends[i];
		launch_thread(&draw_threads[i], draw_worker, &dt);
		wait_thread(draw_threads[i]);
		i++;
	}
	pthread_mutex_destroy(&dt.frac_mutex);
}
