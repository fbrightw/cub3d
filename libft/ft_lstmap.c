/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:20:59 by fbrightw          #+#    #+#             */
/*   Updated: 2021/03/30 15:21:08 by fbrightw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_list;
	void	*content;
	t_list	*element;

	new_list = 0;
	while (lst)
	{
		content = (*f)(lst->content);
		element = 0;
		if (content)
			element = ft_lstnew(content);
		if (element)
			ft_lstadd_back(&new_list, element);
		else
			ft_lstclear(&new_list, del);
		lst = lst->next;
	}
	return (new_list);
}
