/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:38:18 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:38:18 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_find_hor(t_mlx *mlx, double tang)
{
	double dist_x;
	double dist_y;

	dist_x = 0;
	dist_y = 0;
	first_hit_hor(mlx, &dist_x, &dist_y, tang);
	while (mlx->map[mlx->ray.hity_y][mlx->ray.hity_x] != '1')
	{
		if (mlx->hero.fov <= 180.0 && mlx->hero.fov >= 0)
			dist_y -= SCALE;
		else
			dist_y += SCALE;
		if (mlx->hero.fov < 90.0 || mlx->hero.fov > 270.0)
			dist_x += SCALE / tang;
		else
			dist_x -= SCALE / tang;
		ft_seg_sit(mlx, &dist_x, &dist_y);
		mlx->ray.hity_x = (int)(dist_x / SCALE);
		mlx->ray.hity_y = (int)(dist_y / SCALE);
	}
	find_dist(mlx, &dist_x, &dist_y, 1);
}

void	ft_find_vert(t_mlx *mlx, double tang)
{
	double dist_x;
	double dist_y;

	dist_x = 0;
	dist_y = 0;
	first_hit_vert(mlx, &dist_x, &dist_y, tang);
	while (mlx->map[mlx->ray.hitx_y][mlx->ray.hitx_x] != '1')
	{
		if (mlx->hero.fov <= 90.0 || mlx->hero.fov >= 270.0)
			dist_x += SCALE;
		else
			dist_x -= SCALE;
		if (mlx->hero.fov <= 180.0 && mlx->hero.fov > 0)
			dist_y -= SCALE * tang;
		else
			dist_y += SCALE * tang;
		ft_seg_sit(mlx, &dist_x, &dist_y);
		mlx->ray.hitx_x = (int)(dist_x / SCALE);
		mlx->ray.hitx_y = (int)(dist_y / SCALE);
	}
	find_dist(mlx, &dist_x, &dist_y, 0);
}

void	cub3d(t_mlx *mlx, int slice_n, double *distances)
{
	if ((mlx->ray.disty - mlx->ray.distx) > 0.000000001)
	{
		distances[slice_n] = mlx->ray.distx;
		if ((mlx->hero.fov > 90.0 && mlx->hero.fov < 270.0))
			drawing_3d(mlx, slice_n, 0, 2);
		else
			drawing_3d(mlx, slice_n, 0, 3);
	}
	else
	{
		distances[slice_n] = mlx->ray.disty;
		if (mlx->hero.fov >= 0.0 && mlx->hero.fov <= 180.0)
			drawing_3d(mlx, slice_n, 1, 0);
		else
			drawing_3d(mlx, slice_n, 1, 1);
	}
}

void	ft_draw_rays(t_mlx *mlx, int slice_n, double distances[mlx->window.w])
{
	double tang;
	double precision;

	tang = 0;
	mlx->hero.posx = mlx->hero.x * SCALE;
	mlx->hero.posy = mlx->hero.y * SCALE;
	precision = (fabs)(mlx->hero.fov - 270);
	if ((int)(fabs)(cos(mlx->rad)) == 0 && fabs(precision) < 0.000001)
		tang = 0.00000001;
	else
		tang = (fabs)(tan(mlx->rad));
	ft_find_hor(mlx, tang);
	ft_find_vert(mlx, tang);
	if ((int)((fabs)(cos(mlx->rad))) == 0 && fabs(precision) < 0.000001)
		mlx->ray.distx += mlx->ray.disty;
	cub3d(mlx, slice_n, distances);
}

void	ft_raycasting(t_mlx *mlx)
{
	int		i;
	double	distances[mlx->window.w];

	i = 0;
	mlx->hero.fov = mlx->hero.main_degree + 30;
	xpm_to_spr(mlx);
	while (i < mlx->window.w)
	{
		if (mlx->hero.fov >= 360.0)
			mlx->hero.fov -= 360.0;
		if (mlx->hero.fov < 0)
			mlx->hero.fov += 360.0;
		mlx->rad = mlx->hero.fov * M_PI / 180;
		if ((int)(fabs(sin(mlx->rad))) == 0 && fabs(mlx->hero.fov) < 0.000001)
			ft_ew(mlx, i, distances, 'E');
		else if ((int)(fabs(cos(mlx->rad))) == 0 &&\
		fabs(mlx->hero.fov - 270) < 0.000001)
			ft_ns(mlx, i, distances, 'S');
		else
			ft_draw_rays(mlx, i, distances);
		mlx->hero.fov -= ((float)60 / mlx->window.w);
		i++;
	}
	sprites(mlx, distances);
}
