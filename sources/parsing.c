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

void	check_args(int ac, char *map)
{
	if (ac != 2)
	{
		ft_putstr_fd("usage : ", 2);
		ft_putstr_fd(map, 2);
		ft_putendl_fd("./fractol -[mj]", 2);
		exit(EXIT_FAILURE);
	}
}
