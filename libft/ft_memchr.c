/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:24 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:39 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	l;
	unsigned char	*str;

	str = (unsigned char *)s;
	l = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == l)
			return (&str[i]);
		i++;
	}
	return (0);
}
