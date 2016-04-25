/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:49:37 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:33:04 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_coord(char *file_name, t_co *c)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	c->coord = (t_coord *)malloc(sizeof(t_coord));
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		if (i++ == 0)
			x_len = tab_len(split);
		c->coord->x_point = tab_len(split);
		tab_free(split);
		check_len_map(x_len, c->coord);
		free(line);
	}
	check_error(&fd, line, x_len, i);
	c->coord->to_pts = x_len * i;
	c->coord->y_point = i;
	close(fd);
}

void	get_points(t_co *c, int *fd, char *line, int *v)
{
	int		x;
	int		y;
	char	**split;

	x = 0;
	y = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		while (x < c->coord->x_point)
		{
			c->coord->vert[*v] = (t_point *)malloc(sizeof(t_point));
			c->coord->vert[*v]->h = ft_atoi(split[x]);
			c->coord->vert[*v]->x = ((x * c->gap) - (y * c->gap)) + ORIGIN_X;
			c->coord->vert[*v]->y = ((x * c->gap) + (y * c->gap)) / c->div
			+ ORIGIN_Y - (c->coord->vert[*v]->h * c->c_height);
			*v += 1;
			x++;
		}
		tab_free(split);
		free(line);
		x = 0;
		y++;
	}
}

void	stock_coord(char *file_name, t_co *c)
{
	int		fd;
	char	*line;
	int		v;

	v = 0;
	line = NULL;
	init_coord(file_name, c);
	fd = open(file_name, O_RDONLY);
	c->coord->vert = (t_point **)malloc(sizeof(t_point *) * c->coord->to_pts);
	get_points(c, &fd, line, &v);
	close(fd);
}
