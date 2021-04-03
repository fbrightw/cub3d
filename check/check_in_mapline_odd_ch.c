/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_mapline_odd_ch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:39:55 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:39:56 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_odd_in_str(t_mlx *mlx, char *line, char *right, int *ch)
{
	int i;
	int j;

	j = 0;
	while (line[j])
	{
		i = -1;
		while (++i < ft_strlen(right))
		{
			if (line[j] == right[i])
			{
				j++;
				break ;
			}
		}
		if (i > (ft_strlen(right) - 1))
		{
			if (line[j] == *ch)
				j++;
			else
				return (1);
		}
	}
	return (*line == 0 && j == 0) ? write_errors(mlx, 10) : 0;
}

int		check_for_odd_ch(t_mlx *mlx, char *line)
{
	int index;
	int ch;

	index = 0;
	ch = 0;
	if (*line)
	{
		if (ft_strchr_mod(line, "NEWS", &index, &ch))
		{
			if (!(ft_additional(mlx, line, &index, &ch)))
				if ((check_odd_in_str(mlx, line, "012 ", &ch)))
					return (write_errors(mlx, 4));
			return (0);
		}
		else if (check_odd_in_str(mlx, line, "012 ", &ch))
			return (write_errors(mlx, 4));
		if (!(ft_strchr_mod(line, "120 ", &index, &ch)))
			return (write_errors(mlx, 4));
		return (0);
	}
	else
		return (write_errors(mlx, 7));
}

int		check_for_odd_ch_in_res(t_mlx *mlx, char **textures)
{
	int i;
	int j;
	int width;
	int height;

	i = -1;
	check_quantity(mlx, textures);
	mlx_get_screen_size(&width, &height);
	while (textures[++i])
	{
		j = -1;
		while (textures[i][++j])
		{
			if (!(ft_isdigit(textures[i][j])))
			{
				free_text(textures);
				write_errors(mlx, 4);
			}
		}
		if (j > 4 && i == 0)
			mlx->window.w = width;
		if (j > 4 && i == 1)
			mlx->window.h = height;
	}
	return (assigning_w_h(mlx, textures, width, height));
}

void	count_comma(t_mlx *mlx, char *line)
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

int		right_ch(char c, char *right_chs)
{
	int i;

	i = 0;
	while (right_chs[i])
	{
		if (c == right_chs[i])
			return (1);
		i++;
	}
	return (0);
}
