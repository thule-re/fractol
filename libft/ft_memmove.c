/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:27 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:46 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*dstptr;
	const char	*srcptr;

	if (!dst && !src && len != 0)
		return ((void *)0);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	i = len - 1;
	dstptr = (char *)dst;
	srcptr = (const char *)src;
	while (i >= 0)
	{
		dstptr[i] = srcptr[i];
		i--;
	}
	return (dst);
}
