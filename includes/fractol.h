/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:31:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/05/04 00:46:36 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>	 
# include "mlx.h"
# include "libft.h"
# include "keyboard.h"

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define GREY		0x585957
# define SPEBLUE	0xD9853B

# define WIDTH 900 
# define HEIGHT 700 

# define ORIGIN_X (WIDTH / 2)
# define ORIGIN_Y (HEIGHT / 3)

# define MAND	1	
# define JULIA	2	
# define BURN	3

# define MAX_FRACTALS 4
# define NUM_THREADS 4
# define QUATER_WIDTH

typedef	struct			s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char alpha;
}						t_color;

typedef struct			s_point
{
	int				x;
	int 			y;
	int				h;
}						t_point;

typedef struct			s_fpoint
{
	double			x;
	double			y;
}						t_fpoint;

typedef struct			s_image
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_image;

typedef struct			s_frac
{
	int			iter_max;
	t_point		p;
	t_fpoint	p1;
	t_fpoint	p2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		m_r;
	double		m_i;
	double		i;
	double		tmp;
	t_color		black;
	t_color		color;
	int			fract;
}						t_frac;

typedef struct			s_co
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_image				*img;
}						t_co;

typedef	struct	s_thread_info 
{
	t_co	*c;
	t_frac	frac;		
	int		frac_set;
}				t_thread_info;

//remove uselless
typedef struct		s_data_thread
{
	t_image			*img;
	t_frac			*f;
}					t_data_thread;

typedef void *(*fn_draw_worker)(void *p);

void					init_co_img(t_co *c);
void					pixel_put_image(t_image *image, t_point *p);
void					check_args(int ac, char **av, long tab_set[MAX_FRACTALS],
						int *nf);
int						handler_key(int keycode, void *param);
int						handler_mouse(int b,int x, int y, void *p);
void					pixel_put_image_color(t_image *i, t_point *p,
						t_color *c);
void					set_background(t_color *color, t_image *img);
void					menu(t_co *c);
void					julia(t_image *img);
void					mandelbrot(t_image *img);
void					draw_set(t_image *img, t_frac *f);
void					choose_set(int frac, t_thread_info *ti);
void					init_mand(t_frac *f);
void					init_julia(t_frac *f);
void					redraw(int key, t_thread_info *ti, t_point *mp);
int						handler_julia(int b, int x, void *p);
void					modify_julia(t_thread_info *ti, t_point *mp);

#endif
