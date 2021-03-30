/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:43:30 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:43:31 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		draw_floor(t_mlx *mlx, int slice_n, int *k)
{
	int	floor;
	int	i;

	floor = (mlx->window.h - mlx->height_3d) / 2;
	i = 0;
	while (i < floor)
	{
		my_mlx_pixel_put(mlx, slice_n, *k,\
		create_trgb(0, ft_atoi(mlx->f[0]),\
		ft_atoi(mlx->f[1]), ft_atoi(mlx->f[2])));
		i++;
		*k += 1;
	}
}

void		draw_ceil(t_mlx *mlx, int slice_n, int *k)
{
	int	i;
	int	ceil;

	i = 0;
	ceil = (mlx->window.h - mlx->height_3d) / 2;
	while (i < ceil)
	{
		my_mlx_pixel_put(mlx, slice_n, *k, \
		create_trgb(0, ft_atoi(mlx->c[0]), \
		ft_atoi(mlx->c[1]), ft_atoi(mlx->c[2])));
		i++;
		*k += 1;
	}
}

void		draw_wall(t_mlx *mlx, int slice_n, int *k, int i_text)
{
	double	step;
	double	texture_y;
	int		current_color;
	int		i;

	i = 0;
	step = ((float)(mlx->text[i_text]->height) / mlx->height_3d);
	texture_y = (*k - (float)mlx->window.h / 2 + mlx->height_3d / 2) * step;
	if (texture_y < 0)
		texture_y = 0;
	while (i < mlx->height_3d)
	{
		if ((int)(texture_y) >= mlx->text[i_text]->height - 1)
			break ;
		if (i >= mlx->window.h - 1)
			break ;
		current_color = *((unsigned int*)(mlx->text[i_text]->data)\
		+ ((int)(texture_y) * mlx->text[i_text]->width + (int)mlx->texture_x));
		my_mlx_pixel_put(mlx, slice_n, *k, current_color);
		texture_y += step;
		*k += 1;
		i++;
	}
}

void		drawing_3d(t_mlx *mlx, int slice_n, int fl, int i_text)
{
	double	dist;
	int		k;

	k = 0;
	mlx->height_3d = 0;
	mlx->dist_to_proj = 0;
	mlx->texture_x = 0;
	if (fl == 0)
	{
		dist = mlx->ray.distx;
		mlx->texture_x = (int)(((mlx->ray.distx_y - mlx->ray.hitx_y * SCALE)\
		/ SCALE) * mlx->text[i_text]->width - 0.0000000000001);
	}
	else
	{
		dist = mlx->ray.disty;
		mlx->texture_x = (int)(((mlx->ray.disty_x - mlx->ray.hity_x * SCALE)\
		/ SCALE) * mlx->text[i_text]->width - 0.0000000000001);
	}
	mlx->dist_to_proj = (mlx->window.w / 2) / tan(M_PI / 6);
	mlx->height_3d = (double)SCALE /
	 (dist * fabs(cos((mlx->hero.main_degree - mlx->hero.fov) * M_PI / 180)))
	* (double)mlx->dist_to_proj;
	// if (slice_n == mlx->window.w / 2)
	// 	printf("%d %f %d %f %f %d\n", mlx->height_3d, mlx->hero.fov, slice_n, cos((mlx->hero.main_degree - mlx->hero.fov) * M_PI / 180), dist, mlx->dist_to_proj);
	draw_ceil(mlx, slice_n, &k);
	draw_wall(mlx, slice_n, &k, i_text);
	draw_floor(mlx, slice_n, &k);
}
