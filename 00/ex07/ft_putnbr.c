/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:50:07 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/05 17:14:31 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char a);

void	ft_putnbr(int nb)
{
	unsigned int	l;

	l = nb;
	if (nb < 0)
	{
		put_char('-');
		l = -nb;
	}
	if (l < 10)
	{
		put_char(l + 48);
		return ;
	}
	ft_putnbr(l / 10);
	put_char((l % 10) + 48);
}

void	put_char(char a)
{
	write(1, &a, 1);
}
