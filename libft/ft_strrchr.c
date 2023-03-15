/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:00 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:20:24 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	l;

	l = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
