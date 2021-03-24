/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:34:06 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 13:34:07 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		get_max_numb_elements_in_str(t_mlx *mlx, int *max)
{
	int max_new;
	int i;
	int j;

	i = 0;
	max_new = 0;
	while (mlx->map[i])
	{
		j = 0;
		max_new = 0;
		while (mlx->map[i][j])
		{
			max_new++;
			j++;
		}
		if (*max < max_new)
			*max = max_new;
		i++;
	}
}

void		set_frame(char **array, int max_row, int max_column)
{
	int i;
	int j;

	i = 0;
	while (i < max_row + 2)
	{
		j = 0;
		while (j < max_column + 2)
		{
			if (i == 0 || i == max_row + 1)
				array[i][j] = '9';
			else
			{
				if (j == 0 || j == max_column + 1)
					array[i][j] = '9';
				else
					array[i][j] = '*';
			}
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] = 0;
}

char		**set_mem(int max_row, int max_column)
{
	int		i;
	char	**array;

	i = 0;
	array = (char**)malloc(sizeof(char*) * (max_row + 3));
	while (i < max_row + 2)
	{
		array[i] = (char*)malloc(sizeof(char) * (max_column + 3));
		i++;
	}
	return (array);
}

char		**put_frame(t_mlx *mlx, int max_row)
{
	char	**array;
	int		i;
	int		j;
	int		max_column;

	i = 0;
	j = 0;
	max_column = 0;
	get_max_numb_elements_in_str(mlx, &max_column);
	array = set_mem(max_row, max_column);
	set_frame(array, max_row, max_column);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			array[i + 1][j + 1] = mlx->map[i][j];
			j++;
		}
		i++;
	}
	return (array);
}

void		floodfill(t_mlx *mlx, char **array, int x, int y)
{
	if (array[x][y] == '8' || array[x][y] == '1')
		return ;
	if (array[x][y] == '9')
		write_errors(mlx, 7);
	array[x][y] = '8';
	floodfill(mlx, array, x + 1, y);
	floodfill(mlx, array, x, y + 1);
	floodfill(mlx, array, x - 1, y);
	floodfill(mlx, array, x, y - 1);
}

void		validation(t_mlx *mlx, int j)
{
	int		i;
	char	**array;

	i = 0;
	array = put_frame(mlx, j);
	// while (array[i])
	// {
	// 	printf("%s\n", array[i]);
	// 	i++;
	// }
	floodfill(mlx, array, (int)mlx->hero.x, (int)mlx->hero.y);
	printf("floodfill %d %d\n", (int)mlx->hero.x, (int)mlx->hero.y);
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		// free(array[i]);
		i++;
	}
	// free(array);
}
