/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:23:29 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:23:31 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_is_negative(int *new, int fd)
{
	if (*new < 0 && *new != -2147483648)
	{
		write(fd, "-", 1);
		*new = (-1) * (*new);
	}
	if (*new == -2147483648)
	{
		ft_putstr_fd("-214748364", fd);
		*new = 8;
	}
	if (*new == 2147483647)
	{
		ft_putstr_fd("214748364", fd);
		*new %= 10;
	}
}

void	ft_write(int k, int numb, int fd)
{
	int m;

	m = 0;
	while (k > 0)
	{
		m = numb % 10 + '0';
		write(fd, &m, 1);
		numb /= 10;
		k -= 1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int numb;
	int m;
	int k;
	int *new;

	m = 0;
	numb = 0;
	new = &n;
	k = 0;
	ft_is_negative(new, fd);
	while (*new / 10 != 0)
	{
		m = *new % 10;
		*new /= 10;
		numb = 10 * numb + m;
		k += 1;
	}
	m = *new % 10;
	numb = 10 * numb + m;
	k += 1;
	ft_write(k, numb, fd);
}
