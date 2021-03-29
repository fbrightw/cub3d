/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/21 16:39:16 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 16:39:17 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_lstclear(&mlx->lists, free);
	free_text_spr(mlx, 'T');
	free_text_spr(mlx, 'S');
	free_floor_ceil(mlx);
	exit(0);
}

void		draw_everything(t_mlx *mlx, char **map, int color)
{
	ft_raycasting(mlx, color);
	ft_draw_map(mlx);
	if (mlx->argc == 3)
	{
		if (!(ft_strncmp(mlx->argv[2], "--save", 6)))
			screenshot(mlx);
		else
			write_errors(mlx, 10);
	}
	else if (mlx->argc > 2)
		write_errors(mlx, 10);
}

int			key_press(int keycode, t_mlx *mlx)
{
	char	ch;
	double	new_y;
	double	new_x;

	mlx->fl = 0;
	mlx->rad = mlx->hero.main_degree * M_PI / 180;
	mlx_clear_window(mlx->ptr, mlx->win);
	draw_everything(mlx, mlx->map, 0x00000000);
	if (keycode == 123)
		ch = 'l';
	if (keycode == 124)
		ch = 'r';
	if (keycode == 13)
		ch = 'w';
	if (keycode == 0)
		ch = 'a';
	if (keycode == 1)
		ch = 's';
	if (keycode == 2)
		ch = 'd';
	if (!ft_wasd(mlx, ch, new_x, new_y))
		left_right(mlx, keycode);
	draw_everything(mlx, mlx->map, 0x00ff00ff);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

void		ft_create_game(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->window.w, mlx->window.h, "cUB");
	mlx->img.img = mlx_new_image(mlx->ptr, mlx->window.w, mlx->window.h);
	mlx->img.data = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.l_len, &mlx->img.end);
	ft_texturees(mlx);
	draw_everything(mlx, mlx->map, 0x00ff00ff);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
}

void		ft_start(t_mlx *mlx, int argc, char **argv)
{
	mlx->fl = 1;
	if (mlx->hero.dir == 'N')
		mlx->hero.main_degree = 90;
	else if (mlx->hero.dir == 'S')
		mlx->hero.main_degree = 270;
	else if (mlx->hero.dir == 'W')
		mlx->hero.main_degree = 180;
	else if (mlx->hero.dir == 'E')
		mlx->hero.main_degree = 0;
	mlx->argc = argc;
	mlx->argv = argv;
	ft_create_game(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_loop((*mlx).ptr);
}
