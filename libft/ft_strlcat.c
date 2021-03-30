/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:25:01 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:25:04 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		dlen;
	char		*ndst;
	const char	*nsrc;

	i = 0;
	ndst = dst;
	nsrc = src;
	dlen = ft_strlen(dst);
	if (nsrc[i] == 0)
		return (dlen);
	if (dlen < n)
	{
		while (i < (n - dlen - 1) && nsrc[i])
		{
			ndst[i + dlen] = nsrc[i];
			i++;
		}
	}
	else
		return (ft_strlen((char*)src) + n);
	ndst[i + dlen] = '\0';
	return (ft_strlen((char*)src) + dlen);
}
