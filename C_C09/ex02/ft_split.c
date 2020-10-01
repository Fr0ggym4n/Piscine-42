/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:39:26 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/28 19:39:48 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_issep(char *str, char *charset)
{
	while (*charset)
		if (*str == *charset++)
			return (1);
	return (0);
}

int		ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_issep(str + i, charset))
		i++;
	return (i);
}

int		ft_wordcount(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && ft_issep(str, charset))
			str++;
		i = ft_wordlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

char	*ft_wordcpy(char *src, int n)
{
	char	*dest;

	if (!(dest = malloc((n + 1) * sizeof(char))))
		return (0);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		size;
	int		i;
	int		n;

	size = ft_wordcount(str, charset);
	if (!(array = malloc((size + 1) * sizeof(char *))))
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*str && ft_issep(str, charset))
			str++;
		n = ft_wordlen(str, charset);
		if (!(array[i] = ft_wordcpy(str, n)))
			return (0);
		str += n;
	}
	array[size] = 0;
	return (array);
}
