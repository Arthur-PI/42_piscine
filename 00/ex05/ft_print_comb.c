/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:52:21 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/05 17:12:16 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	iter_comb(char a, char b, char c);
void	print_comb(char a, char b, char c);

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '1';
	c = '1';
	iter_comb(a, b, c);
}

void	iter_comb(char a, char b, char c)
{
	char	flag;

	flag = 0;
	while (1)
	{
		c++;
		if (c == ':')
		{
			b++;
			if (b == '9')
			{
				b = ++a + 1;
				if (a == '8')
					break ;
			}
			c = b + 1;
		}
		if (flag)
			write(1, ", ", 2);
		print_comb(a, b, c);
		flag = 1;
	}
}

void	print_comb(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}
