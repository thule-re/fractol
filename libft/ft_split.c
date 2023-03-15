/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treeps <treeps@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:39 by treeps            #+#    #+#             */
/*   Updated: 2022/12/17 17:20:02 by treeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static char	*ft_calloc_range(const char *str, char c)
{	
	int		i;
	char	*range;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	range = (char *)ft_calloc(i + 1, sizeof(char));
	if (!range)
		return (0);
	return (range);
}

static int	ft_count_subs(const char *s, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (i < len)
	{
		count++;
		while (s[i] != c && i < len)
			i++;
		while (s[i] == c && i < len)
			i++;
	}
	return (count);
}

static void	*ft_free_on_fail(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return (0);
}

static char	**ft_alloc_split(const char *s, char c)
{
	char	**result;
	int		subs;
	int		i;

	subs = ft_count_subs(s, c);
	result = (char **)ft_calloc(subs + 1, sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (i < subs)
	{
		result[i] = ft_calloc_range(s, c);
		if (!result[i])
			return (ft_free_on_fail(result, i));
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (result);
}

/// @brief splits a string into substrings using a delimiter
/// @param s the string to split
/// @param c the delimiter to split by
/// @return the allocated array of strings
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s || !s[0])
		return ((char **)ft_calloc(1, sizeof(char *)));
	while (*s == c && *s)
		s++;
	result = ft_alloc_split(s, c);
	if (!result)
		return (0);
	i = 0;
	while (ft_count_subs(s, c))
	{
		j = 0;
		while (s[j] != c && s[j])
			j++;
		ft_memmove(result[i], s, j);
		s += j;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (result);
}

/*
int	main(void)
{
	char	**str = ft_split("      split       this for   me  !     ", ' ');
	int i = 0;

	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	// printf("%d\n", ft_count_subs("split       this for   me  !         ", ' '));
	return (0);
}
*/