/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:18:49 by treeps            #+#    #+#             */
/*   Updated: 2023/02/06 17:19:00 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*new;

	if (newsize == 0)
		return (free(ptr), NULL);
	new = malloc(newsize);
	ft_bzero(new, newsize);
	if (!new)
		return (ptr);
	ft_memmove(new, ptr, oldsize);
	free(ptr);
	return (new);
}
