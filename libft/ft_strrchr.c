/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:27:05 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:27:07 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const void *str, int ch)
{
	int i;

	i = ft_strlen(str);
	while (i > 0 && *(char*)(str + i) != ch)
		i--;
	if (*(char*)(str + i) == ch)
		return (void*)(str + i);
	return (0);
}
