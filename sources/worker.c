#include "fractol.h"

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
