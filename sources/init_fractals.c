#include "fractol.h"

void	init_mand(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_tri(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_bird(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.75;
	f->p1.y = -1.65;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_burn(t_frac *f)
{
	f->c_r = (f->p.x) / f->zoom + f->p1.x;
	f->c_i = (f->p.y) / f->zoom + f->p1.y;
	f->i = 0;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -1.822084;
	f->p1.y = -0.086814;
	f->zoom = 5125;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}

void	init_julia(t_frac *f)
{
	f->i = 0;
	f->c_r = -0.67;
	f->c_i = -0.4159;
	f->p.x = 0;
	f->p.y = 0;
	f->p1.x = -2.3;
	f->p1.y = -1.7;
	f->zoom = 200;
	f->iter_max = 40;
	f->co.r = 0;
	f->co.g = 0;
	f->co.b = 0;
}
