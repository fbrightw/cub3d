/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:29 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 15:08:30 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	vertical(t_mlx *mlx, int i, double *distances, int x)
{
	double		vert_off;
	double		texture_y;
	int			current_color;
	double		scr_size;

	scr_size = (float)mlx->window.w / mlx->spr[i]->dist * 32;
	vert_off = mlx->window.h / 2 - scr_size / 2;
	texture_y = 0;
	mlx->i = 0;
	while (mlx->i < (int)scr_size)
	{
		if (vert_off + mlx->i > mlx->window.h - 1)
			break ;
		current_color = *((unsigned int*)(mlx->spr[i]->data)\
		+ ((int)texture_y * mlx->spr[i]->width + \
		(int)mlx->texture_x));
		// printf("x= %d y = %f\n", x, mlx->h_off + x);
		if (current_color != 0 && (int)(mlx->h_off + x) > 0 && distances[((int)(mlx->h_off + x))]\
		>= mlx->spr[i]->dist)
			my_mlx_pixel_put(mlx, mlx->h_off + x, vert_off + mlx->i,\
			current_color);
		texture_y += (mlx->spr[i]->height / scr_size);
		mlx->i++;
	}
}

void	draw_vert_of_spr(t_mlx *mlx, float deg_pl_spr, double *distances, int i)
{
	double	texture_y;
	double	scr_size;
	int		current_color;
	double	h_off;
	int		x;

	x = 0;
	texture_y = 0;
	mlx->texture_x = 0;
	scr_size = (float)mlx->window.w / mlx->spr[i]->dist * 32;
	h_off = (mlx->hero.main_degree * (M_PI / 180) - deg_pl_spr) / (M_PI / 3) \
	* (mlx->window.w) + (mlx->window.w / 2) - (scr_size / 2);
	while (x < (int)scr_size)
	{
		if (h_off + x > mlx->window.w - 1)
			break ;
		texture_y = 0;
		mlx->h_off = h_off;
		vertical(mlx, i, distances, x);
		x++;
		mlx->texture_x += ((float)mlx->spr[i]->width / scr_size);
	}
}

void	drawing_sprites(t_mlx *mlx, double *distances, int i)
{
	float	degree_between_pl_spr;
	double	delta;
	double	rad;

	if (mlx->spr[i]->dist > 12)
	{
		if (fabs(mlx->spr[i]->y - mlx->hero.y) > 0.000000001)
			delta = mlx->hero.y - mlx->spr[i]->y;
		else
			delta = mlx->spr[i]->y - mlx->hero.y;
		degree_between_pl_spr = atan2(delta, mlx->spr[i]->x - mlx->hero.x);
		rad = degree_between_pl_spr - mlx->hero.main_degree * (M_PI / 180);
		while (rad > M_PI)
		{
			degree_between_pl_spr -= 2 * M_PI;
			rad = degree_between_pl_spr - mlx->hero.main_degree * (M_PI / 180);
		}
		while (rad < -M_PI)
		{
			degree_between_pl_spr += 2 * M_PI;
			rad = degree_between_pl_spr - mlx->hero.main_degree * (M_PI / 180);
		}
		draw_vert_of_spr(mlx, degree_between_pl_spr, distances, i);
	}
}

void	sort_sprites(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->spr_count)
	{
		j = i + 1;
		while (j < mlx->spr_count)
		{
			if (mlx->spr[j]->dist > mlx->spr[i]->dist)
				change(mlx, i, j);
			j++;
		}
		i++;
	}
}

int		find_exact_spr(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->spr_count)
	{
		mlx->spr[i]->dist = hypot(mlx->hero.x - mlx->spr[i]->x, \
		mlx->hero.y - mlx->spr[i]->y) * SCALE;
		i++;
	}
	return (i);
}
