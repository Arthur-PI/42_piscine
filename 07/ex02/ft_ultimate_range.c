/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:08:54 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/17 18:44:38 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SIZE_OF_INT 4

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*tab;

	len = max - min;
	if (len <= 0)
		return (0);
	tab = malloc(len * sizeof(**range));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (len);
}
