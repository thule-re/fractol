/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:38 by treeps            #+#    #+#             */
/*   Updated: 2023/01/10 09:38:37 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i])
	{
		if (ft_putchar_fd(s[i++], fd) == -1)
			return (-1);
	}
	return (i);
}
