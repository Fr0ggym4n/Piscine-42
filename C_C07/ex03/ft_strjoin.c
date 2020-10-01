/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:13:44 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/22 12:43:51 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

int		ft_strfulllenght(char **strings, int size, int len_sep)
{
	int fulllenght;
	int	index;

	fulllenght = 0;
	index = 0;
	while (index < size)
	{
		fulllenght += ft_strlen(strings[index]);
		fulllenght += len_sep;
		index++;
	}
	fulllenght -= len_sep;
	return (fulllenght);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		big_size;
	char	*string;

	i = 0;
	if (size == 0)
		return (string = (char *)malloc(sizeof(char)));
	big_size = ft_strfulllenght(strs, size, ft_strlen(sep));
	if (!(string = malloc((big_size + 1) * sizeof(char))))
		return (0);
	string[0] = '\0';
	while (i < size)
	{
		ft_strcat(string, strs[i]);
		if (i < size - 1)
			ft_strcat(string, sep);
		i++;
	}
	string[big_size] = '\0';
	return (string);
}
