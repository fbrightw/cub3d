/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:20:59 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/23 14:21:00 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < mlx->window.w && (y >= 0 && y < mlx->window.h))
	{
		dst = mlx->img.data + (y * mlx->img.l_len + x * (mlx->img.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		wall_or_sprite(t_mlx *mlx, int i)
{
	int w;
	int h;
	int scale1;

	w = 0;
	h = 0;
	scale1 = mlx->window.w / 100;
	if (mlx->map[i][mlx->window.i] == '1' || mlx->map[i][mlx->window.i] == '2')
	{
		h = i * scale1;
		while (h++ < scale1 + i * scale1)
		{
			w = mlx->window.i * scale1;
			{
				while (w++ < scale1 + mlx->window.i * scale1)
				{
					if (mlx->map[i][mlx->window.i] == '2')
						my_mlx_pixel_put(mlx, w, h, 0x00000000);
					else
						my_mlx_pixel_put(mlx, w, h, 0xcf7b79);
				}
			}
		}
	}
}

void		ft_draw_map(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->size)
	{
		while (mlx->map[i][mlx->window.i])
		{
			wall_or_sprite(mlx, i);
			mlx->window.i++;
		}
		i++;
		mlx->window.i = 0;
	}
}
