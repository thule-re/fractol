/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:40:01 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:18:02 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !s1[0])
		return ((char *)ft_calloc(1, sizeof(char)));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]))
		j--;
	if (j == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	return (ft_substr(s1, i, j - i + 1));
}

//int	main(void)
//{
//	printf("%s", ft_strtrim("hello, worldllll", "l"));
//}