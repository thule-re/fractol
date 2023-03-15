/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:25 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:44 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dstptr;
	const char	*srcptr;

	if (!dst && !src && n != 0)
		return ((void *)0);
	dstptr = (char *)dst;
	srcptr = (const char *)src;
	i = 0;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	return (dst);
}
