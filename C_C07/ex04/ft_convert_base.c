/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:29:17 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/26 17:10:47 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_check_base(char *base);

void	ft_nbto_base(unsigned int nbr, char **str, int size, char *base)
{
	unsigned int	base_len;

	base_len = (unsigned int)ft_check_base(base);
	if (nbr >= base_len)
	{
		ft_nbto_base(nbr / base_len, str, size - 1, base);
		(*str)[size] = base[nbr % base_len];
	}
	else
		(*str)[size] = base[nbr % base_len];
}

char	*ft_itoa(int size, int base_size, int number, char *base_to)
{
	char	*res;
	int		i;

	i = number;
	if (number < 0)
		size++;
	while (i / base_size != 0)
	{
		size++;
		i /= base_size;
	}
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (number < 0)
	{
		number = -number;
		res[0] = '-';
	}
	res[size] = '\0';
	ft_nbto_base((unsigned int)number, &res, size - 1, base_to);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	int		base_size;
	int		size;
	char	*converted;

	size = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	number = ft_atoi_base(nbr, base_from);
	base_size = ft_check_base(base_to);
	if (!base_size)
		return (0);
	converted = ft_itoa(1, base_size, number, base_to);
	while (converted[size])
		size++;
	while (size > 0)
	{
		converted[--size] = base_to[number % base_size];
		number /= base_size;
	}
	return (converted);
}
