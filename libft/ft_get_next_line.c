/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/11/17 11:40:03 by fbrightw          #+#    #+#             */
/*   Updated: 2020/11/23 17:02:37 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup_gnl(const char *s1)
{
	char	*copy;
	size_t	size;
	size_t	i;
	int		fl2;

	fl2 = 0;
	size = ft_strlen_modified_gnl(s1, 0, &fl2);
	copy = (char*)malloc((size + 1) * sizeof(char));
	i = 0;
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = *(char*)(s1 + i);
		i++;
	}
	copy[i] = 0;
	return (copy);
}

int		ft_free(char **s1, int fl)
{
	free(*s1);
	*s1 = NULL;
	if (fl == 0)
		return (0);
	return (-1);
}

int		ft_find_newline(char **str, char **line)
{
	int		len_str;
	char	*newline;
	int		rest;
	int		fl2;

	fl2 = 0;
	len_str = ft_strlen_modified_gnl(*str, 1, &fl2);
	if (!(*line = ft_substr_gnl(*str, 0, len_str)))
		return (ft_free(str, 1));
	if (fl2 == 1)
		rest = ft_strlen_modified_gnl(*str + len_str, 0, &fl2);
	else
		rest = 0;
	if (rest)
		newline = ft_substr_gnl(*str, len_str + 1, rest);
	else
		return (ft_free(str, 0));
	if (newline == 0)
		return (ft_free(str, 1));
	free(*str);
	*str = ft_strdup_gnl(newline);
	free(newline);
	return (1);
}

int		ft_conditions(char **line, char **str, int ret)
{
	if (ret < 0)
		return (ft_free(str, 1));
	else if (ret == 0 && *str == 0)
	{
		if (!(*line = (char *)malloc(sizeof(char))))
			return (-1);
		free(*str);
		**line = '\0';
		*str = NULL;
		return (0);
	}
	return (ft_find_newline(str, line));
}

int		ft_get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char *str;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!str)
	{
		if (!(str = malloc(sizeof(char))))
			return (-1);
		*str = '\0';
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin_gnl(str, buf)))
			return (ft_free(&str, 1));
		free(str);
		str = tmp;
		if (ft_strchr_gnl(str, '\n'))
			break ;
	}
	return (ft_conditions(line, &str, ret));
}
