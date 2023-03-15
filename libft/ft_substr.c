/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:03 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:17:52 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_memmove(str, s + start, len);
	return (str);
}
