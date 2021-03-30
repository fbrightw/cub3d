/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:32:06 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:32:08 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_texts(t_mlx *mlx, char *line, char *fl_of_side)
{
	if (!ft_strncmp(fl_of_side, "NO", 2))
	{
		mlx->no = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "SO", 2))
	{
		mlx->so = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "WE", 2))
	{
		mlx->we = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "EA", 2))
	{
		mlx->ea = ft_strchr(line, '.');
		return (1);
	}
	return (0);
}

void		check_floor_ceil(t_mlx *mlx, char **line)
{
	int i;
	int j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (ft_isdigit((line[i][j])))
				j++;
			else
				write_errors(mlx, 9);
		}
		if (ft_atoi(line[i]) > 255)
			write_errors(mlx, 9);
		else
			i++;
	}
	if (i > 3)
		write_errors(mlx, 4);
}

char		*spaces_or_end(t_mlx *mlx, char *line)
{
	int i;

	i = 0;
	while (*line == ' ')
	{
		line++;
		i += 1;
	}
	if (*line == 0)
	{
		mlx->q_lines += 1;
		return (0);
	}
	return (line);
}

void		ft_assigning_zeroes(int *index, int *ch, t_mlx *mlx)
{
	*index = 0;
	*ch = 0;
	if (!(open_images(mlx, mlx->no)))
		mlx->no = NULL;
	if (!(open_images(mlx, mlx->so)))
		mlx->so = NULL;
	if (!(open_images(mlx, mlx->we)))
		mlx->we = NULL;
	if (!(open_images(mlx, mlx->ea)))
		mlx->ea = NULL;
}

int			fill_certain_texture(t_mlx *mlx, char *line, char fl_of_side[3])
{
	int	index;
	int	ch;

	index = 0;
	ch = 0;
	if (!mlx->no || !mlx->so || !mlx->we || !mlx->ea)
	{
		line++;
		if (*line == fl_of_side[1])
		{
			line++;
			while (*line == ' ')
				line++;
			check_textures(mlx, line, fl_of_side);
			return (init_texts(mlx, line, fl_of_side));
		}
		write_errors(mlx, 4);
	}
	if (strchr_mod(line, "NEWSFC", &index, &ch))
	{
		index += 1;
		if (ft_additional(mlx, line, &index, &ch))
			write_errors(mlx, 6);
	}
	return (0);
}
