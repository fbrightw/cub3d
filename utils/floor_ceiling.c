/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:35:42 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:35:45 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ceiling(t_mlx *mlx, char *line)
{
	if (!(mlx->c))
	{
		line++;
		if (*line == ' ')
		{
			while (*line == ' ')
				line++;
			count_comma(mlx, line);
			mlx->c = ft_split(line, ',');
			check_floor_ceil(mlx, mlx->c);
			return (1);
		}
		return (0);
	}
	write_errors(mlx, 6);
	return (0);
}

int			ft_floor_ceil(t_mlx *mlx, char *line, int *ch)
{
	if (*ch == 'F')
	{
		if (!(mlx->f))
		{
			line++;
			if (*line == ' ')
			{
				while (*line == ' ')
					line++;
				count_comma(mlx, line);
				mlx->f = ft_split(line, ',');
				check_floor_ceil(mlx, mlx->f);
				return (1);
			}
			return (0);
		}
		write_errors(mlx, 6);
	}
	else if (*ch == 'C')
		return (ceiling(mlx, line));
	return (0);
}
