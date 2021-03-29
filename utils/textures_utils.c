/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/23 14:25:49 by fbrightw          #+#    #+#             */
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
			if (!mlx->s)
			{
				if (*(++line) == ' ')
				{
					while (*line == ' ')
						line++;
					check_textures(mlx, line, " ");
					mlx->s = ft_strchr(line, '.');
					return (1);
				}
			}
			write_errors(mlx, 6);
		}
		return (1);
	}
	else if (*ch == 'W')
		return (fill_certain_texture(mlx, line, "WE"));
	else if (*ch == 'E')
		return (fill_certain_texture(mlx, line, "EA"));
	return (0);
}

int			assigning_texts(t_mlx *mlx, char *line, int *index, int *ch)
{
	if (fill_texts(mlx, line, ch))
		return (1);
	if (ft_floor_ceil(mlx, line, index, ch))
		return (1);
	return (0);
}

int			screen_res_newsc(t_mlx *mlx, char *line, char **textures)
{
	int index;
	int ch;

	ch = 0;
	if (*line == 'R')
	{
		if ((ft_strnstr(line, "R ", 2)) && \
		mlx->window.w == -1 && mlx->window.h == -1)
		{
			textures = ft_split(line, ' ');
			if (!(check_for_odd_ch_in_res(mlx, textures)))
			{
				if (mlx->window.w == -1 && mlx->window.h == -1)
				{
					mlx->window.w = ft_atoi(textures[1]);
					mlx->window.h = ft_atoi(textures[2]);
					// check_window(mlx, textures);
					return (1);
				}
				write_errors(mlx, 6);
			}
		}
		(mlx->window.w == -1) ? (write_errors(mlx, 4)) : (write_errors(mlx, 6));
	}
	if (strchr_mod(line, "NEWSFC", &index, &ch))
		return (assigning_texts(mlx, line, &index, &ch));
	return (0);
}

int			find_textures(t_mlx *mlx, char *line)
{
	char	**textures;
	int		index;
	int		ch;

	ft_assigning_zeroes(&index, &ch, mlx);
	if (*line != 0)
		while (*line == ' ')
			line++;
	if (*line == 0)
	{
		mlx->q_lines += 1;
		return (0);
	}
	if (check_before_exit(mlx, line, index, ch))
		if (mlx->no && mlx->so && mlx->we && mlx->ea && mlx->s)
			if (strchr_mod(line, "NEWS", &index, &ch))
			{
				index += 1;
				if (!(ft_additional(mlx, line, &index, &ch)) \
				&& mlx->hero.x != -1)
					write_errors(mlx, 6);
			}
	if (!ft_strchr_mod(line, "NEWSFC120", &index, &ch))
		write_errors(mlx, 4);
	return (screen_res_newsc(mlx, line, textures));
}
