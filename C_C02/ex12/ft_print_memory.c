/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:43:09 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/17 14:46:59 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_hex[16] = "0123456789abcdef";
char g_hex_addr[16];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hex(unsigned long c)
{
	ft_putchar(g_hex[(unsigned char)c / 16]);
	ft_putchar(g_hex[(unsigned char)c % 16]);
}

void	ft_addr_to_hex(long addr)
{
	int i;

	i = 16;
	while (addr)
	{
		g_hex_addr[--i] = g_hex[addr % 16];
		addr /= 16;
	}
	while (i--)
		g_hex_addr[i] = '0';
}

void	ft_print_data(char *string, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size)
	{
		if (!(i % 2))
			ft_putchar(' ');
		ft_put_hex(string[i]);
	}
	while (i < 16)
		write(1, "  ", (i++ % 2 ? 2 : 3));
	ft_putchar(' ');
	i = -1;
	while (++i < size)
		ft_putchar((string[i] < ' ' || string[i] == 127 ? '.' : string[i]));
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_addr_to_hex((long)addr);
		j = 0;
		while (j < 16)
			ft_putchar(g_hex_addr[j++]);
		ft_putchar(':');
		ft_print_data(addr, (size - 1 < 16) ? size - i : 16);
		ft_putchar('\n');
		i += 16;
		addr += 16;
	}
	return (addr);
}
