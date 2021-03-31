/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:24:09 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:24:17 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_count_words(const char *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		k += 1;
		while (s[i] == c && s[i])
			i++;
	}
	return (k);
}

int		ft_count_letters(const char *s, char c)
{
	int k;

	k = 0;
	while (s[k] != c && s[k])
		k++;
	return (k);
}

int		ft_record(char const *s, char **str, int l, int *j)
{
	int i;

	i = 0;
	while (i < l && *(s + i))
	{
		str[*j][i] = *(s + i);
		i++;
	}
	str[*j][i] = '\0';
	*j += 1;
	return (i);
}

char	**ft_main_part(char const *s, char **str, char c, int i)
{
	int j;
	int k;

	j = 0;
	k = ft_count_words(s + i, c);
	while (j < k && s[i])
	{
		s = s + i;
		i = 0;
		if (!(str[j] = (char*)malloc((ft_count_letters(s, c) + 1))))
		{
			while (j--)
				free(str[j]);
			free(str);
			return (0);
		}
		i = ft_record(s, str, ft_count_letters(s, c), &j);
		while (s[i] == c && s[i])
			i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] == c && s[i])
		i++;
	k = ft_count_words(s + i, c);
	if (!(str = (char**)malloc((k + 1) * sizeof(char*))))
		return (0);
	str[k] = 0;
	ft_main_part(s, str, c, i);
	return (str);
}
