/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:24:12 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/15 21:55:20 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_check_lenbase(char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' ||
				str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i]
				== '\f' || str[i] == '\r' || str[i] == ' ')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	else
		return (i);
}

void			ft_print_convert(unsigned int nbr, unsigned int size,
		char *base)
{
	unsigned int	num;

	if (nbr >= size)
		ft_print_convert((nbr / size), size, base);
	num = nbr % size;
	write(1, &base[num], 1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	unsigned int	size;

	if (ft_check_lenbase(base) != 0)
	{
		size = ft_check_lenbase(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			num = -nbr;
		}
		else
			num = nbr;
		ft_print_convert(num, size, base);
	}
	else
		return ;
}
