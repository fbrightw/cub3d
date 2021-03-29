/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_mapline_odd_ch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/29 15:32:53 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/29 15:32:55 by fbrightw         ###   ########.fr       */
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

void	check_for_odd_ch(t_mlx *mlx, char *line)
{
	int index;
	int ch;

	index = 0;
	ch = 0;
	if (*line)
	{
		if (ft_strchr_mod(line, "NEWs", &index, &ch))
		{
			if (!(ft_additional(mlx, line, &index, &ch)))
			{
				if ((check_odd_in_str(mlx, line, "012 ", &ch)))
					write_errors(mlx, 4);
			}
			else
				write_errors(mlx, 6);
		}
		else if (check_odd_in_str(mlx, line, "012 ", &ch))
			write_errors(mlx, 4);
		if (!(ft_strchr_mod(line, "120 ", &index, &ch)))
			write_errors(mlx, 4);
	}
	else
		write_errors(mlx, 7);
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