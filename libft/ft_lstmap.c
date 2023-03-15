/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:08 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:18:12 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	if (!f || !del || !lst)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (0);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		new->next = tmp;
		new = tmp;
		lst = lst->next;
	}
	return (start);
}
