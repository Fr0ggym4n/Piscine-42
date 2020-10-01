/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:06:38 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/11 11:00:24 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (j && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (!j && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			j = 0;
		}
		else
			j = 1;
		i++;
	}
	return (str);
}
