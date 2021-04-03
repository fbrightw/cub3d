/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surronding_in_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:44:01 by fbrightw          #+#    #+#             */
/*   Updated: 2021/04/01 16:44:02 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		to_left(char *line, int index)
{
	while (line[index] != '\0')
	{
		if (line[index] == '1')
			return (1);
		else
			index--;
	}
	return (0);
}

int		to_right(char *line, int index)
{
	while (line[index] != '\0')
	{
		if (line[index] == '1')
			return (1);
		else
			index++;
	}
	return (0);
}

int		to_up(t_mlx *mlx, int index, int row)
{
	int c;

	c = mlx->map[row][index];
	while (row >= 0)
	{
		if (c == '1')
			return (1);
		else
		{
			if (row > 0)
				row--;
			else
				write_errors(mlx, 7);
			c = mlx->map[row][index];
		}
	}
	return (0);
}

int		to_down(t_mlx *mlx, int index, int row)
{
	int c;

	c = mlx->map[row][index];
	while (row <= mlx->size - 1)
	{
		if (c == '1')
			return (1);
		else
		{
			if (row < mlx->size - 1)
				row++;
			else
				return (0);
			c = mlx->map[row][index];
		}
	}
	return (0);
}

void	check_borders(t_mlx *mlx)
{
	int i;
	int j;

	i = -1;
	while (++i < mlx->size)
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == '1')
				;
			else if (right_ch(mlx->map[i][j], "02NEWS "))
			{
				if (!(to_left(mlx->map[i], j)))
					write_errors(mlx, 7);
				if (!(to_right(mlx->map[i], j)))
					write_errors(mlx, 7);
				if (!(to_up(mlx, j, i)))
					write_errors(mlx, 7);
				if (!(to_down(mlx, j, i)))
					write_errors(mlx, 7);
			}
		}
	}
}
