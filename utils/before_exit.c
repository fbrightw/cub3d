/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:29:20 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:29:21 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_text_spr(t_mlx *mlx, char ch)
{
	int i;

	i = 0;
	if (ch == 'T')
	{
		while (i < 4)
		{
			free(mlx->text[i]);
			i++;
		}
		free(mlx->text);
	}
	else if (ch == 'S')
	{
		i = 0;
		while (i < mlx->spr_count)
		{
			free(mlx->spr[i]);
			i++;
		}
		free(mlx->spr);
	}
}

void		free_floor_ceil(t_mlx *mlx)
{
	int i;

	i = 0;
	if (mlx->F)
	{
		while (mlx->F[i])
		{
			free(mlx->F[i]);
			i++;
		}
		free(mlx->F);
	}
	i = 0;
	if (mlx->C)
	{
		while (mlx->C[i])
		{
			free(mlx->C[i]);
			i++;
		}
		free(mlx->C);
	}
}

void		write_errors(t_mlx *mlx, int fl)
{
	ft_lstclear(&mlx->lists, free);
	if (mlx->mem_to_spr == 1)
		free_text_spr(mlx, 'T');
	if (mlx->mem_to_text == 1)
		free_text_spr(mlx, 'S');
	free_floor_ceil(mlx);
	if (fl == 1)
		printf("Error\n with size of window");
	if (fl == 2)
		printf("Error\nNegative size of window");
	if (fl == 3)
		printf("Error\nWrong name of textures");
	if (fl == 4)
		printf("Error\nodd characters");
	if (fl == 5)
		printf("Error\nspaces in wrong places");
	if (fl == 6)
		printf("Error\nduplicates!");
	if (fl == 7)
		printf("Error\nwrong map!!!");
	if (fl == 8)
		printf("Error\nwrong name of map file!!!");
	if (fl == 9)
		printf("Error\ncolors of floor or ceiling is wrong");
	if (fl == 10)
		printf("Error\nsomething wrong with argv");
	if (fl == 11)
		printf("Error\nsomething is missing");
	if (fl == 12)
		printf("Error\ntoo many commas");
	exit(0);
}
