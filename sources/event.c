#include "fractol.h"

int		handler_key(int keycode, void *pa)
{
	t_thread_info	*ti;

	ti = (t_thread_info *)pa;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(ti->c->mlx_ptr, ti->c->img_ptr);
		mlx_destroy_window(ti->c->mlx_ptr, ti->c->win_ptr);
		free(ti->c->img);
		free(ti->c);
		_exit(EXIT_SUCCESS);
	}
	redraw(keycode, ti);
	return (0);
}

int		handler_mouse(int b,int x, int y, void *p)
{
	t_thread_info	*ti;
	t_point			mp;

	ti = (t_thread_info *)p;
	if (y > 0)
	{
		mp.x = x;
		mp.y = y;
		if (b == WHEEL_DOWN)
			zoomout(&ti->frac, &mp, 1.5);
		if (b == WHEEL_UP)
			zoomin(&ti->frac, &mp, 1.5);
	}
	draw_set(ti->c->img, &ti->frac);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	if (ti->show)
		menu(ti->c);
	return (0);
}

int		handler_julia(int x,int y, void *p)
{
	t_thread_info	*ti;
	t_point			mp;

	ti = (t_thread_info *)p;
	if (y > 0 && x > 0 && x < WIDTH && y < HEIGHT && !ti->lock)
	{
		mp.x = x;
		mp.y = y;
		modify_julia(ti, &mp);
	}
	if (ti->show)
		menu(ti->c);
	return (0);
}

void	modify_julia(t_thread_info *ti, t_point *mp)
{
	set_background(&ti->blk, ti->c->img);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	if (mp->x < WIDTH / 2 && mp->y < HEIGHT / 2)
		ti->frac.c_i -= 0.01;
	if (mp->x > WIDTH / 2 && mp->y < HEIGHT / 2)
		ti->frac.c_i += 0.01;
	if (mp->x < WIDTH / 2 && mp->y > HEIGHT / 2)
		ti->frac.c_r += 0.01;
	if (mp->x > WIDTH / 2 && mp->y > HEIGHT / 2)
		ti->frac.c_r -= 0.01;
	draw_set(ti->c->img, &ti->frac);
	mlx_put_image_to_window(ti->c->mlx_ptr, ti->c->win_ptr, ti->c->img_ptr, 0, 0);
	if (ti->show)
		menu(ti->c);
}

