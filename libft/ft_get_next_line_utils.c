/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:17:30 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:17:33 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen_modified_gnl(const char *s, int fl1, int *fl2)
{
	int i;

	i = 0;
	if (fl1 == 1)
	{
		while (s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] == '\n')
			*fl2 = 1;
	}
	else
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*nstr;

	i = 0;
	k = 0;
	if (!(nstr = (char*)malloc((ft_strlen_modified_gnl(s1, 0, NULL) + \
						ft_strlen_modified_gnl(s2, 0, NULL) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		*(char*)(nstr + i) = s1[i];
		i++;
	}
	k = i;
	i = 0;
	while (s2[i] != '\0')
	{
		*(char*)(nstr + k) = s2[i];
		i++;
		k++;
	}
	nstr[k] = '\0';
	return (nstr);
}

char	*ft_strchr_gnl(const void *str, int ch)
{
	int i;

	i = 0;
	while (*(char*)(str + i) != ch && *(char*)(str + i) != 0)
		i++;
	if (*(char*)(str + i) == ch)
		return (char*)(str + i);
	return (0);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char const		*news;
	size_t			i;

	news = s;
	substr = (char*)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!news || !substr)
		return (NULL);
	len = len + start;
	if (start > ft_strlen_modified_gnl(s, 0, NULL))
		return (substr);
	while (start < len && news[start])
	{
		substr[i] = news[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
