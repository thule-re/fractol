/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:58 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:17:57 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (len <= 0)
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && needle[j])
			j++;
		if (!(needle[j]))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
