/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptraddr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:48:28 by treeps            #+#    #+#             */
/*   Updated: 2023/01/10 10:17:18 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_write(unsigned long nb, int fd, int *ret)
{
	unsigned long	baseval;
	char			*base;

	baseval = 16;
	base = "0123456789abcdef";
	if (nb < baseval)
	{
		*ret += write(fd, &base[nb], 1);
	}
	else
	{
		ft_recursive_write(nb / baseval, fd, ret);
		*ret += write(fd, &base[nb % baseval], 1);
	}
}

static int	ft_count_digits(unsigned long i, int base)
{
	int	c;

	c = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= base;
		c++;
	}
	return (c);
}

int	ft_putptraddr_fd(void *p, int fd)
{
	unsigned long	nb;
	int				ret;

	nb = (unsigned long)p;
	ret = ft_putstr_fd("0x", 1);
	if (ret == -1)
		return (-1);
	ft_recursive_write(nb, fd, &ret);
	if (ret != ft_count_digits(nb, 16) + 2)
		return (-1);
	return (ret);
}
