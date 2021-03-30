/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:21:45 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:21:48 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				a;
	unsigned char		*ndst;
	unsigned const char	*nsrc;

	a = 0;
	ndst = dst;
	nsrc = src;
	while (a < n)
	{
		if (nsrc[a] == (unsigned char)c)
		{
			ndst[a] = nsrc[a];
			return (&(ndst[a + 1]));
		}
		ndst[a] = nsrc[a];
		a++;
	}
	return (NULL);
}
