/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/03/21 13:20:00 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/21 13:20:02 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void			find_pl(char *line, t_mlx *mlx, int y, char dir)
{
	int i;

	i = 0;
	if (mlx->hero.y == -1 && mlx->hero.x == -1)
	{
		mlx->hero.y = y + 0.5;
		while (line[i] != dir)
			i++;
		mlx->hero.x = i + 0.5;
		mlx->hero.dir = dir;
	}
	else
		write_errors(mlx, 13);
}

static void		assiging_zero(int *i, int *index, int *ch, int *count)
{
	*i = 0;
	*index = 0;
	*ch = 0;
	*count = 0;
}

int				map_filling(t_mlx *mlx, t_list *head)
{
	int i;
	int index;
	int ch;
	int count;

	assiging_zero(&i, &index, &ch, &count);
	while (head)
	{
		if (i >= mlx->q_lines)
		{
			mlx->map[i - mlx->q_lines] = head->content;
			check_line(mlx, mlx->map[i - mlx->q_lines]);
			if (ft_strchr_mod(mlx->map[i - mlx->q_lines], "NEWs", &index, &ch))
				find_pl(mlx->map[i - mlx->q_lines], mlx, i - mlx->q_lines, ch);
			count_spr(mlx, i - mlx->q_lines, &count);
		}
		i++;
		head = head->next;
	}
	mlx->map[i - mlx->q_lines] = 0;
	find_spr(mlx, &count);
	return (i - mlx->q_lines);
}

t_list			*ft_reading(t_mlx *mlx, int fd, char *line)
{
	t_list	*head;
	int		i;
	int		ret;

	i = 0;
	head = NULL;
	while ((ret = ft_get_next_line(fd, &line)) > 0)
	{
		i++;
		ft_lstadd_back(&head, ft_lstnew(line));
		if (find_textures(mlx, line) == 1)
			mlx->q_lines++;
	}
	if (ret == -1)
		write_errors(mlx, 10);
	else
		ft_lstadd_back(&head, ft_lstnew(line));
	mlx->size = i + 1;
	return (head);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			i;
	t_mlx		mlx;

	i = 0;
	line = NULL;
	zeros_to_var_in_mlx(&mlx);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		write_errors(&mlx, 8);
	mlx.lists = ft_reading(&mlx, fd, line);
	if (!(mlx.map = ft_calloc(mlx.size - mlx.q_lines + 2, sizeof(char*))))
	{
		ft_lstclear(&(mlx.lists), free);
		exit(0);
	}
	i = map_filling(&mlx, mlx.lists);
	validation(&mlx, i);
	mlx.size = mlx.size - mlx.q_lines;
	close(fd);
	ft_start(&mlx, argc, argv);
}
