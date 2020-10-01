/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:22:12 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/16 15:45:54 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!base)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < '!' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '-' || base[i] == '+' ||
					base[i] < '!' || base[i] > 126)
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

int				ft_base_check(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_convert(unsigned int size, char *str, char *base)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_base_check(str[i], base) >= 0)
		{
			result = result * size + ft_base_check(str[i], base);
			i++;
		}
		else
			break ;
	}
	return (result);
}

int				ft_atoi_base(char *str, char *base)
{
	int				i;
	int				negativ;
	unsigned int	size;

	i = 0;
	if (ft_check_base(base) != 0)
	{
		size = ft_check_base(base);
		while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		negativ = 1;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				negativ *= -1;
			i++;
		}
		return (ft_atoi_convert(size, str + i, base) * negativ);
	}
	else
		return (0);
}
