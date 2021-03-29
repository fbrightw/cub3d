/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/29 15:38:12 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/29 15:38:13 by fbrightw         ###   ########.fr       */
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

int			ft_floor_ceil(t_mlx *mlx, char *line, int *index, int *ch)
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
