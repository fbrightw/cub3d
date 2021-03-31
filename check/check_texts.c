/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:29:34 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:29:36 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		open_images(char *line)
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
	if (mlx->no && mlx->so && mlx->we && mlx->ea && mlx->f && mlx->c && mlx->s)
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
	if (!(open_images(line)))
		write_errors(mlx, 3);
	if (!ft_strncmp(fl_of_side, "NO", 2))
		if (mlx->no != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "SO", 2))
		if (mlx->so != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "WE", 2))
		if (mlx->we != NULL)
			write_errors(mlx, 6);
	if (!ft_strncmp(fl_of_side, "EA", 2))
		if (mlx->ea != NULL)
			write_errors(mlx, 6);
}
