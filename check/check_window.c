/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:49:26 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 14:49:28 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_text(char **textures)
{
	int i;

	i = 0;
	while (textures[i])
	{
		free(textures[i]);
		i++;
	}
	free(textures);
}

void	check_quantity(t_mlx *mlx, char **textures)
{
	int i;

	i = 0;
	while (textures[i])
		i++;
	if (i > 2 || i < 2)
	{
		free_text(textures);
		write_errors(mlx, 1);
	}
}

void	check_size(t_mlx *mlx, char **textures)
{
	if (mlx->window.w < 80)
		write_errors(mlx, 1);
	if (mlx->window.h < 50)
		write_errors(mlx, 1);
	free_text(textures);
}

int		assigning_w_h(t_mlx *mlx, char **textures, int width, int height)
{
	if (mlx->window.w == -1 && mlx->window.h == -1)
	{
		mlx->window.w = (ft_atoi(textures[0]) < width) ?\
		(ft_atoi(textures[0])) : (width);
		mlx->window.h = (ft_atoi(textures[1]) < height) ?\
		(ft_atoi(textures[1])) : (height);
	}
	if (mlx->window.w == -1)
	{
		if (ft_atoi(textures[0]) < 80)
			write_errors(mlx, 1);
		else
			mlx->window.w = (ft_atoi(textures[0]) < width) ?\
			(ft_atoi(textures[0])) : (width);
	}
	else if (mlx->window.h == -1)
	{
		if (ft_atoi(textures[1]) < 80)
			write_errors(mlx, 1);
		else
			mlx->window.h = (ft_atoi(textures[1]) < height) ?\
			(ft_atoi(textures[1])) : (height);
	}
	check_size(mlx, textures);
	return (1);
}
