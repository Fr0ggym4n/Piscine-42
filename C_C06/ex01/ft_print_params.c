/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:12:31 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/16 16:32:17 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = argc;
	if (argc > 1)
	{
		while (!(argc == 0))
			argc--;
		while (argv[argc++] && !(argc == i))
		{
			ft_putstr(argv[argc]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
