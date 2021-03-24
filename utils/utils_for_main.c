/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:20:27 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 13:20:30 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			find_exact_ch(char *s, char *str, int *fl, int *ch)
{
	int i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (ft_strchr(str, s[i]) != 0)
		{
			*ch = s[i];
			*fl = 1;
			break ;
		}
		i++;
	}
}

int				ft_strchr_mod(char *str, char *s, int *index, int *ch)
{
	int i;
	int fl;

	i = 0;
	fl = 0;
	find_exact_ch(s, str, &fl, ch);
	if (fl)
	{
		i = 0;
		while (str[i] != *ch && str[i] != '\0')
			i++;
		if (str[i] == *ch)
		{
			*index = i;
			return (1);
		}
	}
	return (0);
}

int				strchr_mod(char *str, char *s, int *index, int *ch)
{
	int i;

	i = 0;
	while (*str == ' ')
		str++;
	while (i < ft_strlen(s))
	{
		if (*str == s[i])
		{
			*ch = *str;
			return (1);
		}
		i++;
	}
	return (0);
}

void			zeros_to_var_in_mlx(t_mlx *mlx)
{
	mlx->size = 0;
	mlx->q_lines = 0;
	mlx->window.i = 0;
	mlx->ray.distY = 0;
	mlx->ray.HitYx = 0;
	mlx->ray.HitYy = 0;
	mlx->hero.x = -1;
	mlx->hero.y = -1;
	mlx->i = 0;
}

void			floodfill(t_mlx *mlx, char **array, int x, int y)
{
	if (array[x][y] == '8' || array[x][y] == '1')
		return ;
	if (array[x][y] == '9')
		write_errors(mlx, 7);
	array[x][y] = '8';
	floodfill(mlx, array, x + 1, y);
	floodfill(mlx, array, x, y + 1);
	floodfill(mlx, array, x - 1, y);
	floodfill(mlx, array, x, y - 1);
}
