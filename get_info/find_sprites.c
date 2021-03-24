/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:14:07 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 15:14:11 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		count_spr(t_mlx *mlx, int j, int *count)
{
	int		i;
	char	ch;
	char	*str;

	str = mlx->map[j];
	ch = '2';
	i = 0;
	while (str[i] != ch && str[i] != 0)
		i++;
	if (str[i] == ch)
		*count += 1;
}

void		set_mem_for_spr(t_mlx *mlx, int *count)
{
	int i;

	i = 0;
	mlx->spr_count = *count;
	if (!(mlx->spr = (t_sprites**)malloc(mlx->spr_count * sizeof(t_sprites*))))
		exit(0);
	while (i < *count)
	{
		if (!(mlx->spr[i] = (t_sprites*)malloc(sizeof(t_sprites))))
			exit(0);
		i++;
	}
}

void		init_spr_coord(t_mlx *mlx, int *spr_n, int i, int j)
{
	double diff_pl_sp_x;
	double diff_pl_sp_y;

	diff_pl_sp_x = mlx->hero.x - mlx->spr[*spr_n]->x;
	diff_pl_sp_y = mlx->hero.y - mlx->spr[*spr_n]->y;
	mlx->spr[*spr_n]->x = j + 0.5;
	mlx->spr[*spr_n]->y = i + 0.5;
	mlx->spr[*spr_n]->dist = hypot(diff_pl_sp_x, diff_pl_sp_y) * SCALE;
	*spr_n += 1;
}

void		find_spr(t_mlx *mlx, int *count)
{
	int i;
	int spr_n;
	int j;
	int diff_pl_sp;

	i = 0;
	spr_n = 0;
	set_mem_for_spr(mlx, count);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '2')
				init_spr_coord(mlx, &spr_n, i, j);
			j++;
		}
		i++;
	}
}

void	change(t_mlx *mlx, int i, int j)
{
	double temp_x;
	double temp_y;
	double temp_dist;

	temp_x = mlx->spr[i]->x;
	temp_y = mlx->spr[i]->y;
	temp_dist = mlx->spr[i]->dist;
	mlx->spr[i]->x = mlx->spr[j]->x;
	mlx->spr[i]->y = mlx->spr[j]->y;
	mlx->spr[i]->dist = mlx->spr[j]->dist;
	mlx->spr[j]->x = temp_x;
	mlx->spr[j]->y = temp_y;
	mlx->spr[j]->dist = temp_dist;
}
