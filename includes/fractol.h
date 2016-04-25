/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:31:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 20:37:08 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
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

# define WIDTH 1000 
# define HEIGHT 700 

# define ORIGIN_X (WIDTH / 2)
# define ORIGIN_Y (HEIGHT / 3)

typedef	struct			s_bres
{
	int					dx;
	int					dy;
	int					e;
	int					x_incr;
	int					y_incr;
	int					c_dx;
	int					c_dy;
	int					ex;
	int					ey;
}						t_bres;

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

typedef struct			s_coord
{
	int					x_point;
	int					y_point;
	int					to_pts;
	t_point				**vert;
}						t_coord;

typedef struct			s_image
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_image;

typedef struct			s_co
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_image				*img;
	t_coord				*coord;
	int					gap;
	int					c_height;
	int					line_color;
	t_color				bg_color;
	int					*colors;
	int					div;
}						t_co;

void					mandelbrot(t_image *img);
void					init_co_img(t_co *c, t_image *im);
void					rot(t_coord *coord, int div, int gap, int c_height);
void					height(t_coord *coord, int n_y);
void					translate(t_coord *coord, int x_axis, int y_axis);
void					zoom(t_coord *coord, int gap, int c_height, int d);
void					scale(t_coord *coord, float x_axis, float y_axis);
void					draw_x_or_y(int x1, int y1, int x2, int y2, t_image *i);
void					draw_vert(t_coord *coord, t_image *img);
void					pixel_put_image(t_image *image, t_point *p);
void					check_args(int ac, char *av);
int						handler(int keycode, void *param);
void					menu(t_co *c);
void					pixel_put_image_color(t_image *i, t_point *p,
						t_color *c);
void					set_background(t_color *color, t_image *img);
void					matrix_mult(int mi[3][3], t_point *p);
void					menu(t_co *c);
void					rotate(t_coord *co, int angle);

#endif
