/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:36 by treeps            #+#    #+#             */
/*   Updated: 2023/01/10 13:56:51 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write(int fd, char *buf, int size, int *err)
{
	if (*err != -1)
		*err = write(fd, buf, size);
	return (*err);
}

static void	ft_rec_write(unsigned int n, int fd, int *ret, int *err)
{
	if (n < 10)
	{
		n += '0';
		*ret += ft_write(fd, (char *)&n, 1, err);
	}
	else
	{
		ft_rec_write(n / 10, fd, ret, err);
		n = (n % 10) + '0';
		*ret += ft_write(fd, (char *)&n, 1, err);
	}
}

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	ret;
	int	err;

	err = 0;
	ret = 0;
	ft_rec_write(n, fd, &ret, &err);
	if (err == -1)
		return (-1);
	return (ret);
}
