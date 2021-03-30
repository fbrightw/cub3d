/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:16:54 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:16:58 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char*)malloc(count * size);
	if (arr == NULL)
		return (NULL);
	while (i < count * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
