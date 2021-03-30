/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:25:23 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:25:26 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		i;
	char		*ndest;
	const char	*nsrc;

	i = 0;
	ndest = dest;
	nsrc = src;
	if (!ndest || !nsrc)
		return (0);
	if (dstsize > 1)
	{
		while (i < dstsize - 1 && nsrc[i])
		{
			ndest[i] = nsrc[i];
			i++;
		}
		ndest[i] = 0;
	}
	return (ft_strlen(nsrc));
}
