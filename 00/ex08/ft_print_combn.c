/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 09:17:59 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/10 20:28:52 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void	ft_comb_rec(int n, int value, char *str_nombre, int n_max)
{
	char	a;

	a = value;
	while (a < 10 - n)
	{
		str_nombre[n_max - n - 1] = a + '0';
		if (n != 0)
			ft_comb_rec(n - 1, a + 1, str_nombre, n_max);
		else
		{
			ft_putstr(str_nombre);
			if (str_nombre[0] != (10 - n_max) + '0')
				ft_putstr(", ");
		}
		a++;
	}
}

void	ft_print_combn(int n)
{
	char	string[10];

	if (n < 1 || n > 9)
		return ;
	string[n] = 0;
	ft_comb_rec(n - 1, 0, string, n);
}
