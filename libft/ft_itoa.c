/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:38:56 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:19:07 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_to_arr(char *result, int n, int *i)
{
	if (n < 0)
	{
		result[*i] = '-';
		(*i)++;
		ft_int_to_arr(result, n * -1, i);
	}
	else if (n < 10)
	{
		result[*i] = n + '0';
		(*i)++;
	}
	else
	{
		ft_int_to_arr(result, n / 10, i);
		ft_int_to_arr(result, n % 10, i);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		nbr;
	int		i;

	nbr = n;
	size = 1;
	if (nbr <= 0)
		size++;
	while (nbr != 0)
	{
		size++;
		nbr /= 10;
	}
	str = (char *)ft_calloc(size, sizeof(char));
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		ft_memmove(str, "-2147483648", 12);
		return (str);
	}
	i = 0;
	ft_int_to_arr(str, n, &i);
	return (str);
}
