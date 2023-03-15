/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:36 by treeps            #+#    #+#             */
/*   Updated: 2023/01/06 14:41:37 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase10_fd(int n, int fd, int *ret)
{
	if (n < 0)
	{
		*ret += ft_putchar_fd('-', fd);
		if (n > -10)
		{
			*ret += ft_putchar_fd((char)n * -1 + '0', fd);
			return ;
		}
		ft_putnbrbase10_fd((n / 10) * -1, fd, ret);
		ft_putnbrbase10_fd((n % 10) * -1, fd, ret);
	}
	else if (n < 10)
	{
		n += '0';
		*ret += ft_putchar_fd((char)n, fd);
	}
	else
	{
		ft_putnbrbase10_fd(n / 10, fd, ret);
		n = (n % 10) + '0';
		*ret += ft_putchar_fd((char)n, fd);
	}
}
