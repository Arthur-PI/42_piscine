/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:21:52 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/05 19:01:48 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(int *tab, int a, int b)
{
	int	tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			swap(tab, i, i - 1);
			if (i > 1)
				i--;
			else
				i++;
		}
		else
			i++;
	}
}
