/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:20:33 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/08 14:36:09 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	l;

	l = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		l = -nb;
	}
	if (l < 10)
		ft_putchar(l + '0');
	else
	{
		ft_putnbr(l / 10);
		ft_putchar((l % 10) + '0');
	}
}
