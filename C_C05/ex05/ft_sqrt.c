/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:27:35 by chcampet          #+#    #+#             */
/*   Updated: 2020/09/15 15:22:19 by chcampet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int root;

	root = 1;
	if (nb <= 0)
		return (0);
	while (root <= 46340 && root * root <= nb)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}
