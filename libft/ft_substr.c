/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:27:27 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:27:29 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_substr(char const *s, int start, int len)
{
	char		*substr;
	char const	*news;
	int			i;

	news = s;
	substr = NULL;
	substr = (char*)ft_calloc((len + 1), sizeof(char));
	i = 0;
	if (!news || !substr)
		return (NULL);
	len = len + start;
	if (start > ft_strlen(s))
		return (substr);
	while (start < len && news)
	{
		substr[i] = news[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
