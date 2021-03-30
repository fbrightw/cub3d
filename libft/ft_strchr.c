/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:24:25 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:24:27 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const void *str, int ch)
{
	int i;

	i = 0;
	while (*(char*)(str + i) != ch && *(char*)(str + i) != 0)
		i++;
	if (*(char*)(str + i) == ch)
		return (char*)(str + i);
	return (0);
}
