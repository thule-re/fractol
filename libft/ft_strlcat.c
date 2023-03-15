/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:49 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:20:12 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstlen + srclen < dstsize - 1)
		len = srclen;
	else
		len = dstsize - dstlen - 1;
	ft_memmove(dst + (int)dstlen, src, len);
	if (dstlen < dstsize)
		dst[dstlen + len] = '\0';
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}
