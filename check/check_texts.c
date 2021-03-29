/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:12:32 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 15:12:38 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_window(t_mlx *mlx, char **textures)
{
	int height;
	int width;
	int i;

	i = 0;
	while (textures[i])
	{
		free(textures[i]);
		i++;
	}
	free(textures);
	if (i > 3)
		write_errors(mlx, 4);
	if (i < 3)
		write_errors(mlx, 4);
	mlx_get_screen_size(&width, &height);
	if (mlx->window.w <= 0 || mlx->window.h <= 0)
		write_errors(mlx, 1);
	if (mlx->window.w > width || mlx->window.h > height)
	{
		mlx->window.w = width;
		mlx->window.h = height;
	}
	if (mlx->window.w < 80 || mlx->window.h < 50)
		write_errors(mlx, 1);
}

int		open_images(t_mlx *mlx, char *line)
{
	int fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int		ft_additional(t_mlx *mlx, char *line, int *index, int *ch)
{
	if (*ch == 'N')
		if (line[*index] == 'O')
			write_errors(mlx, 6);
	if (*ch == 'S')
		if (line[*index] == 'O')
			write_errors(mlx, 6);
	if (*ch == 'W')
		if (line[*index] == 'E')
			write_errors(mlx, 6);
	if (*ch == 'E')
		if (line[*index] == 'A')
			write_errors(mlx, 6);
	return (0);
}

int		check_line(t_mlx *mlx, char *line)
{
	if (mlx->NO && mlx->SO && mlx->WE && mlx->EA && mlx->F && mlx->C && mlx->S)
	{
		while (*line == ' ')
			line++;
		check_for_odd_ch(mlx, line);
	}
	else
		write_errors(mlx, 11);
	return (1);
}

void	check_textures(t_mlx *mlx, char *line, char *fl_of_side)
{
	if (!(open_images(mlx, line)))
		write_errors(mlx, 3);
	if (!ft_strncmp(fl_of_side, "NO", 2))
		if (mlx->NO != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "SO", 2))
		if (mlx->SO != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "WE", 2))
		if (mlx->WE != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "EA", 2))
		if (mlx->EA != NULL)
			write_errors(mlx, 6);
}
