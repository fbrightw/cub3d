#include "../includes/cub3d.h"

void		screenshot(t_mlx *mlx)
{
	int fd;
	int size;
	char arr_info[54];
	int  w = mlx->window.w;
	int h = mlx->window.h;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,0666);
	while (w % 4 != 0)
		w--;
	size = 54 + (4 * w * h);
	ft_memset(arr_info, 0, 54);
	arr_info[0] = 'B';
	arr_info[1] = 'M';
	arr_info[2] = size;
	arr_info[3] = size >> 8;
	arr_info[4] = size >> 16;
	arr_info[5] = size >> 24;
	arr_info[10] = 54;
	arr_info[14] = 40;
	arr_info[26] = 0;
	arr_info[28] = 24;
	arr_info[18] = w;
	arr_info[19] = w >> 8;
	arr_info[20] = w >> 16;
	arr_info[21] = w >> 24;
	arr_info[22] = h;
	arr_info[23] = h >> 8;
	arr_info[24] = h >> 16;
	arr_info[25] = h >> 24;
	write(fd, arr_info, 54);
	int var[3];
	var[0] = h - 1;
	while (var[0] >= 0)
	{
		var[1] = 0;
		while (var[1] < w)
		{
			var[2] = *(int*)(mlx->img.data + (var[0] * mlx->img.l_len + var[1] * (mlx->img.bpp / 8)));
			write(fd, &var[2], 3);
			var[1]++;
		}
		var[0]--;
	}
	close(fd);
	exit(0);
}
