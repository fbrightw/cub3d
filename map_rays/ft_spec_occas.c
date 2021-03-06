/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_occas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:37:11 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:37:12 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ew(t_mlx *mlx, int slice_numb, double *distances, char side)
{
	double	sidedistx;
	double	deltax;
	double	positiv_cos;
	int		fl_text;

	mlx->ray.hitx_y = (int)(mlx->hero.y * SCALE / SCALE);
	mlx->ray.hitx_x = (int)(mlx->hero.x * SCALE / SCALE);
	positiv_cos = (fabs)(cos(mlx->rad));
	sidedistx = mlx->hero.x * SCALE;
	fl_text = (side == 'E') ? 3 : 2;
	while (mlx->map[mlx->ray.hitx_y][mlx->ray.hitx_x] != '1')
	{
		if ((int)(positiv_cos) == 1 && (fabs)(mlx->hero.fov) < 0.000001)
			sidedistx += 1;
		else
			sidedistx -= 1;
		mlx->ray.hitx_x = (int)(sidedistx / SCALE);
	}
	deltax = fabs(mlx->hero.posx - sidedistx);
	mlx->ray.distx = deltax;
	distances[slice_numb] = mlx->ray.distx;
	drawing_3d(mlx, slice_numb, 0, fl_text);
}

void	ft_ns(t_mlx *mlx, int slice_numb, double *distances, char side)
{
	double	sidedisty;
	double	deltay;
	double	positiv_cos;
	double	diff;
	int		fl_text;

	mlx->ray.hity_y = (int)(mlx->hero.y * SCALE / SCALE);
	mlx->ray.hity_x = (int)(mlx->hero.x * SCALE / SCALE);
	diff = mlx->hero.fov - 270;
	positiv_cos = (fabs)(cos(mlx->rad));
	sidedisty = mlx->hero.y * SCALE;
	fl_text = (side == 'N') ? 0 : 1;
	while (mlx->map[mlx->ray.hity_y][mlx->ray.hity_x] != '1')
	{
		if ((int)positiv_cos == 0 && ((mlx->hero.fov - 270) < 0.000001))
			sidedisty += 0.1;
		else
			sidedisty -= 0.1;
		mlx->ray.hity_y = (int)(sidedisty / SCALE);
	}
	distances[slice_numb] = mlx->ray.disty;
	deltay = fabs(mlx->hero.posy - sidedisty);
	drawing_3d(mlx, slice_numb, 1, fl_text);
}
