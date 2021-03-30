/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:22:40 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:22:44 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *dst, int a, size_t n)
{
	size_t c;

	c = 0;
	while (c < n)
	{
		*(unsigned char*)(dst + c) = (unsigned char)(a);
		c++;
	}
	return (dst);
}
