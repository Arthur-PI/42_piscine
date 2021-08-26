/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:20:36 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/23 15:49:08 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(int a)
{
	if (a < 0)
		return (-1);
	else if (a > 0)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	order;

	i = 0;
	order = 1;
	while (i < length - 1 && (*f)(tab[i], tab[i + 1]) == 0)
		i++;
	if (i < length - 1 && (*f)(tab[i], tab[i + 1]) == 1)
		order = -1;
	i = 0;
	while (i < length - 1)
	{
		if (ft_compare((*f)(tab[i], tab[i + 1])) == order)
			return (0);
		i++;
	}
	return (1);
}
