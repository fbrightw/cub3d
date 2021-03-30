/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:22:05 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:22:07 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	size_t					a;
	unsigned const char		*newdst;

	a = 0;
	newdst = dst;
	while (a < n)
	{
		if (newdst[a] == (unsigned char)c)
			return (void*)(dst + a);
		a++;
	}
	return (NULL);
}
