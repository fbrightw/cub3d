/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/23 14:29:20 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:29:21 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_text_spr(t_mlx *mlx, char ch)
{
	int i;

	i = 0;
	if (ch == 'T')
	{
		while (i < 4)
		{
			free(mlx->text[i]);
			i++;
		}
		free(mlx->text);
	}
	else if (ch == 's')
	{
		i = 0;
		while (i < mlx->spr_count)
		{
			free(mlx->spr[i]);
			i++;
		}
		free(mlx->spr);
	}
}

void	free_floor_ceil(t_mlx *mlx)
{
	int i;

	i = 0;
	if (mlx->f)
	{
		while (mlx->f[i])
		{
			free(mlx->f[i]);
			i++;
		}
		free(mlx->f);
	}
	i = 0;
	if (mlx->c)
	{
		while (mlx->c[i])
		{
			free(mlx->c[i]);
			i++;
		}
		free(mlx->c);
	}
}

int		check_before_exit(t_mlx *mlx, char *line, int index, int ch)
{
	if (mlx->no && mlx->so && mlx->we && mlx->ea && mlx->s && mlx->f && mlx->c)
	{
		if (!ft_strchr_mod(line, "NEWS120 ", &index, &ch))
			write_errors(mlx, 4);
		if (ft_strchr_mod(line, "FC", &index, &ch))
			write_errors(mlx, 6);
		if (strchr_mod(line, "NEWS", &index, &ch))
		{
			index += 1;
			if (!(ft_additional(mlx, line, &index, &ch)))
				if (mlx->hero.x != -1)
					write_errors(mlx, 6);
		}
		if (check_line(mlx, line))
			return (0);
	}
	return (1);
}

int		write_errors_part2(t_mlx *mlx, int fl)
{
	if (fl == 8)
		printf("Error\nwrong name of map file!!!");
	if (fl == 9)
		printf("Error\ncolors of floor or ceiling is wrong");
	if (fl == 10)
		printf("Error\nsomething wrong with argv");
	if (fl == 11)
		printf("Error\nsomething is missing");
	if (fl == 12)
		printf("Error\ntoo many commas");
	if (fl == 13)
		printf("Error\nwe need just one player!");
	if (fl == 14)
		printf("Error\nThere is no corner");
	exit(0);
}

int		write_errors(t_mlx *mlx, int fl)
{
	ft_lstclear(&mlx->lists, free);
	if (mlx->mem_to_spr == 1)
		free_text_spr(mlx, 'T');
	if (mlx->mem_to_text == 1)
		free_text_spr(mlx, 'S');
	free_floor_ceil(mlx);
	if (fl == 1)
		printf("Error\nWrong size of window");
	if (fl == 3)
		printf("Error\nWrong name of textures");
	if (fl == 4)
		printf("Error\nodd characters");
	if (fl == 5)
		printf("Error\nspaces in wrong places");
	if (fl == 6)
		printf("Error\nduplicates!");
	if (fl == 7)
		printf("Error\nwrong map!!!");
	write_errors_part2(mlx, fl);
	exit(0);
}
