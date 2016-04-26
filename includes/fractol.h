/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:31:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/26 19:11:52 by cattouma         ###   ########.fr       */
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

typedef struct			s_co
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	t_image				*img;
	t_color				bg_color;
}						t_co;

void					mandelbrot(t_image *img);
void					init_co_img(t_co *c, t_image *im);
void					pixel_put_image(t_image *image, t_point *p);
void					check_args(int ac, char *av, t_co *c);
int						handler(int keycode, void *param);
void					pixel_put_image_color(t_image *i, t_point *p,
						t_color *c);
void					set_background(t_color *color, t_image *img);
void					menu(t_co *c);
void					julia(t_image *img);

#endif
