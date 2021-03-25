/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_occas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:50:06 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 16:50:07 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ew(t_mlx *mlx, int slice_numb, double *distances, char side)
{
	double	sidedistx;
	double	deltax;
	double	positiv_cos;
	int		fl_text;

	mlx->ray.HitXy = (int)(mlx->hero.y * SCALE / SCALE);
	mlx->ray.HitXx = (int)(mlx->hero.x * SCALE / SCALE);
	positiv_cos = (fabs)(cos(mlx->rad));
	sidedistx = mlx->hero.x * SCALE;
	fl_text = (side == 'E') ? 3 : 2;
	while (mlx->map[mlx->ray.HitXy][mlx->ray.HitXx] != '1')
	{
		if ((int)(positiv_cos) == 1 && (fabs)(mlx->hero.fov) < 0.000001)
			sidedistx += 1;
		else
			sidedistx -= 1;
		mlx->ray.HitXx = (int)(sidedistx / SCALE);
	}
	deltax = fabs(mlx->hero.posx - sidedistx);
	mlx->ray.distX = deltax;
	mlx->ray.distx_y = mlx->hero.y * SCALE;
	distances[slice_numb] = mlx->ray.distX;
	drawing_3d(mlx, slice_numb, 0, fl_text);
}

void	ft_ns(t_mlx *mlx, int slice_numb, double *distances, char side)
{
	double	sidedisty;
	double	deltay;
	double	positiv_cos;
	double	diff;
	int		fl_text;

	mlx->ray.HitYy = (int)(mlx->hero.y * SCALE / SCALE);
	mlx->ray.HitYx = (int)(mlx->hero.x * SCALE / SCALE);
	diff = mlx->hero.fov - 270;
	positiv_cos = (fabs)(cos(mlx->rad));
	sidedisty = mlx->hero.y * SCALE;
	fl_text = (side == 'N') ? 0 : 1;
	while (mlx->map[mlx->ray.HitYy][mlx->ray.HitYx] != '1')
	{
		if ((int)positiv_cos == 0 && ((fabs)(diff) < 0.000001))
			sidedisty += 1;
		else
			sidedisty -= 1;
		mlx->ray.HitYy = (int)(sidedisty / SCALE);
	}
	distances[slice_numb] = mlx->ray.distY;
	deltay = fabs(mlx->hero.posy - sidedisty);
	mlx->ray.disty_x = mlx->hero.x * SCALE;
	mlx->ray.distY = deltay;
	drawing_3d(mlx, slice_numb, 1, fl_text);
}
