/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:22:51 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/15 15:39:32 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int prime;
	int index;

	prime = 1;
	index = 2;
	if (nb <= 1)
		return (0);
	while (index < nb)
	{
		if (nb % index == 0)
			prime = 0;
		index++;
	}
	if (prime == 1)
		return (1);
	return (0);
}
