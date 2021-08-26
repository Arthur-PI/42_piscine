/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:48:35 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/17 18:23:10 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define INT_SIZE	4

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	lentab;

	lentab = max - min;
	if (lentab <= 0)
		return (NULL);
	tab = malloc(lentab * INT_SIZE);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < lentab)
	{
		tab[i++] = min;
		min++;
	}
	return (tab);
}
