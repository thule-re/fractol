/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:02 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:16 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (!*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone(curr, del);
		curr = temp;
	}
	*lst = (void *)0;
}
