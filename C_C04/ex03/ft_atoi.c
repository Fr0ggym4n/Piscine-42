/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:27:31 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/14 17:13:46 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int negativ;
	int convert;

	i = 0;
	negativ = 1;
	convert = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negativ *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		convert = convert * 10 + str[i++] - '0';
	return (convert * negativ);
}
