/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:30:40 by cattouma          #+#    #+#             */
/*   Updated: 2016/04/25 17:32:35 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_map(char *map)
{
	int fd;

	if ((fd = open(map, O_RDONLY)) == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
}

int			check_args(int ac, char *map)
{
	if (ac != 2)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(map, 2);
		ft_putendl_fd("./fractol <map>", 2);
		exit(EXIT_FAILURE);
	}
	check_map(map);
	return (EXIT_SUCCESS);
}

void		check_error(int *fd, char *line, int x, int y)
{
	if (get_next_line(*fd, &line) < 0)
	{
		ft_putendl_fd("Not a valid file", 2);
		exit(EXIT_FAILURE);
	}
	if (x == 0 && y == 0)
	{
		ft_putendl_fd("Empty map", 2);
		exit(EXIT_FAILURE);
	}
}

void		check_len_map(int x_len, t_coord *coord)
{
	if (x_len != coord->x_point)
	{
		ft_putendl_fd("Map not well formatted", 2);
		exit(EXIT_FAILURE);
	}
}
