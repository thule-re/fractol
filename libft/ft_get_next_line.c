/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:52:12 by treeps            #+#    #+#             */
/*   Updated: 2023/02/01 12:09:26 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	char	*str;
	char	cop[1];
	int		i;

	if (fd < 0)
		return (NULL);
	str = NULL;
	i = 0;
	*cop = 0;
	while (read(fd, cop, 1) > 0)
	{
		str = (char *)ft_realloc(str, i, (i + 2) * sizeof(char));
		str[i++] = *cop;
		str[i + 1] = 0;
		if (*cop == '\n')
			return (str);
	}
	if (i > 0)
		return (str);
	free(str);
	return (NULL);
}
