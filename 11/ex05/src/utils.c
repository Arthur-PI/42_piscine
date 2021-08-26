/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:58:28 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/23 21:47:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int	ft_getindex(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (i - 1);
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	{
		ft_putchar(l + 48);
		return ;
	}
	ft_putnbr(l / 10);
	ft_putchar((l % 10) + 48);
}
