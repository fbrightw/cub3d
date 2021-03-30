/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_func_draw_everything.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:32:47 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:32:49 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_assigning(t_mlx *mlx, double new_x, double new_y, char ch)
{
	int		add_x;
	int		add_y;
	double	rad;

	rad = (ch == 'a' || ch == 'd') ? (M_PI / 2) : (0);
	add_y = (ch == 'w') ? (8 * sin(mlx->rad)) : (-8 * sin(mlx->rad));
	add_x = (ch == 'd') ? (8 * cos(mlx->rad)) : (-8 * cos(mlx->rad));
	if ((int)new_y > 0 && \
	(int)new_x < (ft_strlen(mlx->map[(int)new_y]) - 1) && \
	(int)new_x > -1 && (int)new_y < mlx->size && \
	mlx->map[(int)((new_y * SCALE + add_y) / SCALE)]\
	[(int)((new_x * SCALE + add_x) / SCALE)] != '1')
		if (mlx->map[(int)(new_y * SCALE / SCALE)]\
		[(int)(new_x * SCALE / SCALE)] != '1' && \
		mlx->map[(int)new_y][(int)new_x] != ' ')
		{
			{
				mlx->hero.y = new_y;
				mlx->hero.x = new_x;
				return (1);
			}
			return (0);
		}
	return (0);
}

int			ft_wasd(t_mlx *mlx, char ch, double new_x, double new_y)
{
	mlx->rad = mlx->hero.main_degree * M_PI / 180;
	if (ch == 'w')
	{
		new_y = mlx->hero.y - (STEP * sin(mlx->rad));
		new_x = mlx->hero.x + (STEP * cos(mlx->rad));
	}
	if (ch == 'a')
	{
		new_x = mlx->hero.x + (STEP * cos(mlx->rad - M_PI / 2));
		new_y = mlx->hero.y + (STEP * sin(mlx->rad - M_PI / 2));
	}
	if (ch == 's')
	{
		new_y = mlx->hero.y + (STEP * sin(mlx->rad));
		new_x = mlx->hero.x - (STEP * cos(mlx->rad));
	}
	if (ch == 'd')
	{
		new_x = mlx->hero.x - (STEP * cos(mlx->rad - M_PI / 2));
		new_y = mlx->hero.y - (STEP * sin(mlx->rad - M_PI / 2));
	}
	return (ft_assigning(mlx, new_x, new_y, ch));
}

void		left_right(t_mlx *mlx, int keycode)
{
	if (keycode == 123)
	{
		if (mlx->hero.main_degree >= 360)
			mlx->hero.main_degree -= 360;
		if (mlx->hero.main_degree < 0)
			mlx->hero.main_degree += 360;
		mlx->hero.main_degree += 5;
		mlx->rad = mlx->hero.main_degree * M_PI / 180;
	}
	if (keycode == 124)
	{
		if (mlx->hero.main_degree >= 360)
			mlx->hero.main_degree -= 360;
		if (mlx->hero.main_degree < 0)
			mlx->hero.main_degree += 360;
		mlx->hero.main_degree -= 5;
		mlx->rad = mlx->hero.main_degree * M_PI / 180;
	}
	if (keycode == 53)
	{
		close_window(mlx);
		exit(0);
	}
}
