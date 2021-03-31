/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:16:22 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:16:27 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(const char *str)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int i;
	int n;
	int k;
	int fl;

	n = 0;
	fl = 0;
	i = ft_isspace(str);
	k = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		fl = 1;
		n = str[i] - '0' + n * 10;
		i++;
	}
	if (fl == 0)
		return (0);
	if (str[k] == '-')
		return (n * (-1));
	return (n);
}
