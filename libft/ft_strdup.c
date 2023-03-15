/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:43 by treeps            #+#    #+#             */
/*   Updated: 2023/01/05 10:14:44 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i])
		i++;
	cpy = (char *)ft_calloc(i + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
