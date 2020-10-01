/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:15:35 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/21 15:24:41 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int index;

	if (min >= max)
		return (0);
	if (!(*range = malloc((max - min) * sizeof(int))))
		return (-1);
	index = 0;
	while (min < max)
	{
		(*range)[index] = min;
		index++;
		min++;
	}
	return (index);
}
