/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:15:32 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/12 19:57:16 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *start;
	char *comp;

	while (str != '\0')
	{
		start = str;
		comp = to_find;
		while (*str && *comp && *str == *comp)
		{
			str++;
			comp++;
		}
		if (*comp == '\0')
			return (start);
		if (comp != 0 && *str == '\0')
			return (0);
		str = start + 1;
	}
	return (str);
}
