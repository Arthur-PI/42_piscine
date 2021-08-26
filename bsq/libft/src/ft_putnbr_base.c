/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:06:38 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/09 20:06:42 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *s)
{
	int	i;
	int	tab[255];

	i = 0;
	while (i < 255)
		tab[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (tab[(int)s[i]] || s[i] == '+' || s[i] == '-')
			return (-1);
		tab[(int)s[i]] = 1;
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

void	ft_putnbr_base_rec(int nbr, char *base, int b_size)
{
	unsigned int	l;

	l = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		l = -nbr;
	}
	if (l < (unsigned int)b_size)
		ft_putchar(base[l]);
	else
	{
		ft_putnbr_base_rec(l / b_size, base, b_size);
		ft_putnbr_base_rec(l % b_size, base, b_size);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_size;

	b_size = check_base(base);
	if (b_size == -1)
		return ;
	ft_putnbr_base_rec(nbr, base, b_size);
}
