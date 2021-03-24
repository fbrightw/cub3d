/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:19:24 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:19:26 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_texts(t_mlx *mlx, char *line, char *fl_of_side)
{
	if (!ft_strncmp(fl_of_side, "NO", 2))
	{
		mlx->NO = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "SO", 2))
	{
		mlx->SO = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "WE", 2))
	{
		mlx->WE = ft_strchr(line, '.');
		return (1);
	}
	else if (!ft_strncmp(fl_of_side, "EA", 2))
	{
		mlx->EA = ft_strchr(line, '.');
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
	printf("%s\n", line);
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
	if (!(open_images(mlx, mlx->NO)))
		mlx->NO = NULL;
	if (!(open_images(mlx, mlx->SO)))
		mlx->SO = NULL;
	if (!(open_images(mlx, mlx->WE)))
		mlx->WE = NULL;
	if (!(open_images(mlx, mlx->EA)))
		mlx->EA = NULL;
}

int			fill_certain_texture(t_mlx *mlx, char *line, char fl_of_side[3])
{
	int		index;
	char	ch;

	index = 0;
	ch = 0;
	if (!mlx->NO || !mlx->SO || !mlx->WE || !mlx->EA)
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
	return (0);
}
