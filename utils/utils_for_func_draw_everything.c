/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_func_draw_everything.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:18:44 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:18:45 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_assigning(t_mlx *mlx, double new_x, double new_y)
{
	if (mlx->map[(int)(new_y)][(int)(new_x)] != '1')
	{
		mlx->hero.y = new_y;
		mlx->hero.x = new_x;
		return (1);
	}
	return (0);
}

int			ft_wasd(t_mlx *mlx, char ch, double new_x, double new_y)
{
	mlx->rad = mlx->hero.main_degree * M_PI / 180;
	if (ch == 'w')
	{
		new_y = mlx->hero.y - (float)(step_pl * sin(mlx->rad));
		new_x = mlx->hero.x + (float)(step_pl * cos(mlx->rad));
		return (ft_assigning(mlx, new_x, new_y));
	}
	if (ch == 'a')
	{
		new_x = mlx->hero.x - (float)(step_pl * cos(mlx->rad));
		new_y = mlx->hero.y - (float)(step_pl * sin(mlx->rad));
		return (ft_assigning(mlx, new_x, new_y));
	}
	if (ch == 's')
	{
		new_y = mlx->hero.y + (float)(step_pl * sin(mlx->rad));
		new_x = mlx->hero.x - (float)(step_pl * cos(mlx->rad));
		return (ft_assigning(mlx, new_x, new_y));
	}
	if (ch == 'd')
	{
		new_x = mlx->hero.x + (float)(step_pl * cos(mlx->rad));
		new_y = mlx->hero.y + (float)(step_pl * sin(mlx->rad));
		return (ft_assigning(mlx, new_x, new_y));
	}
	return (0);
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
