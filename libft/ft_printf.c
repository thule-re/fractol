/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:05:27 by treeps            #+#    #+#             */
/*   Updated: 2023/01/19 16:31:13 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle(char c, va_list argptr)
{
	if (c == '%')
		return (write(1, &c, 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(argptr, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(argptr, char *), 1));
	else if (c == 'p')
		return (ft_putptraddr_fd(va_arg(argptr, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putint_fd(va_arg(argptr, int), 1));
	else if (c == 'u')
		return (ft_putuint_fd(va_arg(argptr, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_fd(va_arg(argptr, unsigned int), BASE16LC, 1));
	else if (c == 'X')
		return (ft_putnbr_fd(va_arg(argptr, unsigned int), BASE16UC, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		ret;
	int		temp;

	va_start(argptr, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			temp = handle(*(++str), argptr);
			if (temp == -1)
				return (-1);
			ret += temp;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			ret++;
		}
		str++;
	}
	va_end(argptr);
	return (ret);
}

// va_start, va_arg, va_copy, va_end, va_list
