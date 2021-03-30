/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:22:21 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:22:23 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t a;

	a = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (a < n)
	{
		*(char*)(dst + a) = *(char*)(src + a);
		a++;
	}
	return (dst);
}
