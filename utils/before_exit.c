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

void		free_everything(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(mlx->text[i]);
		i++;
	}
	free(mlx->text);
	i = 0;
	while (i < mlx->spr_count)
	{
		free(mlx->spr[i]);
		i++;
	}
	free(mlx->spr);
}

void		write_errors(t_mlx *mlx, int fl)
{
	if (fl == 1)
		printf("Error with size of window");
	if (fl == 2)
		printf("Negative size of window");
	if (fl == 3)
		printf("Wrong name of textures");
	if (fl == 4)
		printf("odd characters");
	if (fl == 5)
		printf("spaces in wrong places");
	if (fl == 6)
		printf("duplicates!");
	if (fl == 7)
		printf("wrong map!!!");
	if (fl == 8)
		printf("wrong name of map file!!!");
	exit(0);
}
