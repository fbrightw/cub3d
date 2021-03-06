/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:20:06 by fbrightw          #+#    #+#             */
/*   Updated: 2020/11/11 18:07:01 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*ft_lstlast(t_list *lst)
{
	int i;

	i = 0;
	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		i--;
		lst = lst->next;
	}
	return (lst);
}
