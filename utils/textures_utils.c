/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:25:49 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:25:50 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			fill_texts(t_mlx *mlx, char *line, int *ch)
{
	if (*ch == 'N')
		return (fill_certain_texture(mlx, line, "NO"));
	else if (*ch == 'S')
	{
		if (!(fill_certain_texture(mlx, line, "SO")))
		{
			if (!mlx->S)
			{
				line++;
				if (*line == ' ')
				{
					while (*line == ' ')
						line++;
					mlx->S = ft_strchr(line, '.');
					return (1);
				}
			}
			write_errors(mlx, 6);
			return (0);
		}
		return (1);
	}
	else if (*ch == 'W')
		return (fill_certain_texture(mlx, line, "WE"));
	else if (*ch == 'E')
		return (fill_certain_texture(mlx, line, "EA"));
	return (0);
}

void		count_comma(t_mlx *mlx, char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count += 1;
		i++;
	}
	if (count > 2)
		write_errors(mlx, 12);
}

int			ceiling(t_mlx *mlx, char *line)
{
	if (!(mlx->C))
	{
		line++;
		if (*line == ' ')
		{
			while (*line == ' ')
				line++;
			count_comma(mlx, line);
			mlx->C = ft_split(line, ',');
			check_floor_ceil(mlx, mlx->C);
			return (1);
		}
		return (0);
	}
	write_errors(mlx, 6);
	return(0);
}

int			ft_floor_ceil(t_mlx *mlx, char *line, int *index, int *ch)
{
	if (*ch == 'F')
	{
		if (!(mlx->F))
		{
			line++;
			if (*line == ' ')
			{
				while (*line == ' ')
					line++;
				count_comma(mlx, line);
				mlx->F = ft_split(line, ',');
				check_floor_ceil(mlx, mlx->F);
				return (1);
			}
			return (0);
		}
		write_errors(mlx, 6);
	}
	else if (*ch == 'C')
		return (ceiling(mlx, line));
	return (0);
}

void		check_for_odd_ch_in_res(t_mlx *mlx, char **textures)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (textures[i])
	{
		j = 0;
		if (i > 0)
		{
			while (textures[i][j])
			{
				if (!(ft_isdigit(textures[i][j])))
					write_errors(mlx, 4);
				j++;
			}
		}
		i++;
	}
}

int			screen_res_newsc(t_mlx *mlx, char *line, char **textures)
{
	int index;
	int ch;

	ch = 0;
	if (mlx->window.w == -1 && mlx->window.h == -1)
	{
		if ((ft_strnstr(line, "R ", 2)))
		{
			textures = ft_split(line, ' ');
			check_for_odd_ch_in_res(mlx, textures);
			if (mlx->window.w == -1 && mlx->window.h  == -1)
			{
				mlx->window.w = ft_atoi(textures[1]);
				mlx->window.h = ft_atoi(textures[2]);
				check_window(mlx, textures);
				return (1);
			}
			write_errors(mlx, 6);
		}
		write_errors(mlx, 4);
	}
	if (strchr_mod(line, "NEWSFC", &index, &ch))
	{
		if (fill_texts(mlx, line, &ch))
			return (1);
		if (ft_floor_ceil(mlx, line, &index, &ch))
			return (1);
		return (0);
	}
	return (0);
}

int			find_textures(t_mlx *mlx, char *line)
{
	char	**textures;
	int		index;
	int		ch;

	ch = 0;
	ft_assigning_zeroes(&index, &ch, mlx);
	if (*line != 0)
		while (*line == ' ')
			line++;
	if (*line == 0)
	{
		mlx->q_lines += 1;
		return (0);
	}
	if (mlx->NO && mlx->SO && mlx->WE && mlx->EA && mlx->S && mlx->F && mlx->C)
	{
		if (!ft_strchr_mod(line, "NEWS120", &index, &ch))
			write_errors(mlx, 4);
		if (ft_strchr_mod(line, "FC", &index, &ch))
			write_errors(mlx, 6);
		if (strchr_mod(line, "NEWS", &index, &ch))
			if (!(ft_additional(mlx, line, &index, &ch)))
				if (mlx->hero.x != -1)
					write_errors(mlx, 6);
		if (check_line(mlx, line))
			return (0);
	}
	else if (mlx->NO && mlx->SO && mlx->WE && mlx->EA && mlx->S)
	{
		if (strchr_mod(line, "NEWS", &index, &ch))
		{
			index += 1;
			if (!(ft_additional(mlx, line, &index, &ch)))
				if (mlx->hero.x != -1)
					write_errors(mlx, 6);
		}
	}
	if (!ft_strchr_mod(line, "NEWSFC120", &index, &ch))
		write_errors(mlx, 4);
	return (screen_res_newsc(mlx, line, textures));
	return (0);
}
