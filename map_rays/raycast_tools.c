/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:37:38 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:37:41 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_seg_sit(t_mlx *mlx, double *dist_x, double *dist_y)
{
	int y;

	y = (*dist_y / SCALE);
	if (y < 0)
		*dist_y = 0;
	if (y >= mlx->size)
		*dist_y = (mlx->size - 1) * SCALE;
	y = (*dist_y / SCALE);
	if (*dist_x < 0)
		*dist_x = 0;
	if (y < mlx->size)
		if ((int)(*dist_x / SCALE) >= (ft_strlen(mlx->map[y])) - 1)
			*dist_x = (ft_strlen(mlx->map[y]) - 1) * SCALE;
}

void	first_hit_hor(t_mlx *mlx, double *dist_x, double *dist_y, double tang)
{
	if (mlx->hero.fov <= 180.0 && mlx->hero.fov > 0)
		*dist_y = (int)(mlx->hero.posy / SCALE) * SCALE - 0.00000001;
	else
		*dist_y = (int)(mlx->hero.posy / SCALE) * SCALE + SCALE;
	if (tang != 0.0)
	{
		if (mlx->hero.fov <= 90.0 || mlx->hero.fov > 270.0)
			*dist_x = mlx->hero.posx + (fabs)(mlx->hero.posy - *dist_y) / tang;
		else
			*dist_x = mlx->hero.posx - (fabs)(mlx->hero.posy - *dist_y) / tang;
	}
	else
		*dist_x = mlx->hero.posx;
	ft_seg_sit(mlx, dist_x, dist_y);
	mlx->ray.hity_x = (int)(*dist_x / SCALE);
	mlx->ray.hity_y = (int)(*dist_y / SCALE);
}

void	first_hit_vert(t_mlx *mlx, double *dist_x, double *dist_y, double tang)
{
	if (mlx->hero.fov <= 90.0 || mlx->hero.fov >= 270.0)
		*dist_x = (int)(mlx->hero.posx / SCALE) * SCALE + SCALE;
	else
		*dist_x = (int)(mlx->hero.posx / SCALE) * SCALE - 0.00000001;
	if (mlx->hero.fov <= 180.0 && mlx->hero.fov > 0)
		*dist_y = mlx->hero.posy - (fabs)(*dist_x - mlx->hero.posx) * tang;
	else
		*dist_y = mlx->hero.posy + (fabs)(*dist_x - mlx->hero.posx) * tang;
	ft_seg_sit(mlx, dist_x, dist_y);
	mlx->ray.hitx_x = (int)(*dist_x / SCALE);
	mlx->ray.hitx_y = (int)(*dist_y / SCALE);
}

void	find_dist(t_mlx *mlx, double *dist_x, double *dist_y, int fl)
{
	double delta_x;
	double delta_y;

	delta_x = mlx->hero.posx - *dist_x;
	delta_y = mlx->hero.posy - *dist_y;
	if (fl == 1)
	{
		mlx->ray.disty_x = *dist_x;
		mlx->ray.disty_y = *dist_y;
		mlx->ray.disty = hypot(delta_x, delta_y);
	}
	else
	{
		mlx->ray.distx_x = *dist_x;
		mlx->ray.distx_y = *dist_y;
		mlx->ray.distx = hypot(delta_x, delta_y);
	}
}

void	sprites(t_mlx *mlx, double *distances)
{
	int i;

	i = 0;
	find_exact_spr(mlx);
	sort_sprites(mlx);
	while (i < mlx->spr_count)
	{
		drawing_sprites(mlx, distances, i);
		i++;
	}
}
