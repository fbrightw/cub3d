/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:22:13 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:22:15 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t					i;
	unsigned char const		*nstr1;
	unsigned char const		*nstr2;

	i = 0;
	nstr1 = str1;
	nstr2 = str2;
	while (i < n)
	{
		if (nstr1[i] == nstr2[i])
			i++;
		else
			return (nstr1[i] - nstr2[i]);
	}
	return (0);
}
