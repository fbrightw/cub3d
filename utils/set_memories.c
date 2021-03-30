/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_memories.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:34:33 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:34:35 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		set_mem_to_text(t_mlx *mlx)
{
	int i;

	i = 0;
	if (!(mlx->text = (t_wall_texture**)malloc(4 * sizeof(t_wall_texture*))))
		exit(0);
	while (i < 4)
	{
		if (!(mlx->text[i] = (t_wall_texture*)malloc(sizeof(t_wall_texture))))
			exit(0);
		i++;
	}
	mlx->mem_to_text = 1;
}

void		ft_texturees(t_mlx *mlx)
{
	int		i;

	i = 0;
	set_mem_to_text(mlx);
	while (i < 4)
	{
		if (i == 0)
			mlx->text[i]->path = mlx->no;
		if (i == 1)
			mlx->text[i]->path = mlx->so;
		if (i == 2)
			mlx->text[i]->path = mlx->we;
		if (i == 3)
			mlx->text[i]->path = mlx->ea;
		mlx->text[i]->img = mlx_xpm_file_to_image(mlx->ptr, \
		mlx->text[i]->path, &mlx->text[i]->width, &mlx->text[i]->height);
		mlx->text[i]->data = (unsigned int*)mlx_get_data_addr(\
		mlx->text[i]->img, &mlx->text[i]->bpp, &mlx->text[i]->line_len,\
		&mlx->text[i]->endian);
		i++;
	}
}

void		xpm_to_spr(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->spr_count)
	{
		mlx->spr[i]->path = mlx->s;
		mlx->spr[i]->img = mlx_xpm_file_to_image(mlx->ptr, mlx->s,\
		&mlx->spr[i]->width, &mlx->spr[i]->height);
		mlx->spr[i]->data = (unsigned int*)mlx_get_data_addr(mlx->spr[i]->img,\
		&mlx->spr[i]->bpp, &mlx->spr[i]->line_len, &mlx->spr[i]->end);
		i++;
	}
}
