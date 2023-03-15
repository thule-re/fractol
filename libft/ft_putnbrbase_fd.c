/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:31:18 by treeps            #+#    #+#             */
/*   Updated: 2023/01/11 09:53:05 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_check_base(char *base)
{
	int			i;
	char		temp[128];

	i = -1;
	while (++i < 128)
		temp[i] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+'
			|| base[i] == '-'
			|| ft_strchr(temp, base[i]))
			return (0);
		temp[i] = base[i];
		i++;
	}
	return (i);
}

static void	ft_write(int fd, char *buf, int size, int *err)
{
	int	temp;

	if (*err != -1)
	{
		temp = write(fd, buf, size);
		if (temp != -1)
			*err += temp;
		else
			*err = -1;
	}
}

static void	ft_rec_write(unsigned int nb, char *base, int fd, int *ret)
{
	unsigned int	baseval;

	baseval = ft_check_base(base);
	if (baseval < 2)
	{
		*ret = -1;
		return ;
	}
	if (*ret == -1)
		return ;
	if (nb < baseval)
	{
		ft_write(fd, &base[nb], 1, ret);
	}
	else
	{
		ft_rec_write(nb / baseval, base, fd, ret);
		ft_write(fd, &base[nb % baseval], 1, ret);
	}
}

int	ft_putnbr_fd(unsigned int nb, char *base, int fd)
{
	int				ret;
	unsigned int	baseval;

	ret = 0;
	baseval = ft_check_base(base);
	if (baseval < 2)
		return (-1);
	ft_rec_write(nb, base, fd, &ret);
	return (ret);
}
