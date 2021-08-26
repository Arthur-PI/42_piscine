/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:56:58 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/08 09:00:05 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	iter_comb(char a, char b, char c, char d);
void	print_comb(char a, char b, char c, char d);

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	iter_comb(a, b, c, d);
}

void	iter_comb(char a, char b, char c, char d)
{
	while (1)
	{
		if (++d > '9')
		{
			d = '0';
			if (++c > '9')
			{
				c = '0';
				if (++b > '9')
				{
					b = '0';
					if (++a > '9')
						break ;
				}
			}
		}
		print_comb(a, b, c, d);
	}
}

void	print_comb(char a, char b, char c, char d)
{
	if (a < c || (a == c && b < d))
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (!(a == '9' && b == '8' && c == '9' && d == '9'))
			write(1, ", ", 2);
	}
}
