/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:24:34 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:24:36 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
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
