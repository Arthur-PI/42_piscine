/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:08:49 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/09 15:49:11 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*int_to_hex(char *hex_value, unsigned char c)
{
	unsigned char	c1;
	unsigned char	c2;
	char			*base;

	base = "0123456789abcdef";
	c1 = c / 16;
	c2 = c % 16;
	hex_value[0] = base[(int)c1];
	hex_value[1] = base[(int)c2];
	return (hex_value);
}

void	ft_putnbr_base16(char *res, size_t nbr, int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		res[i] = base[nbr];
	}
	else
	{
		ft_putnbr_base16(res, nbr / 16, i - 1);
		res[i] = base[nbr % 16];
	}
}

void	ft_print_memory_line(char *s_addr, unsigned int size, char *addr_string)
{
	char			hex_value[2];
	char			ascii_string[17];
	unsigned int	i;

	ft_putnbr_base16(addr_string, (size_t)(s_addr), 15);
	write(1, addr_string, 16);
	write(1, ": ", 2);
	i = 0;
	while (i < size && i < 16)
	{
		if (s_addr[i] < 32 || s_addr[i] > 126)
			ascii_string[i] = '.';
		else
			ascii_string[i] = s_addr[i];
		write(1, int_to_hex(hex_value, s_addr[i]), 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	size = (size * 5) / 2;
	while (size++ < 40)
		write(1, " ", 1);
	write(1, ascii_string, i);
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	char	*s_addr;
	char	addr_string[17];
	int		i;

	i = 0;
	while (i < 16)
		addr_string[i++] = '0';
	i = size;
	s_addr = addr;
	while (i > 0)
	{
		ft_print_memory_line(s_addr, i, addr_string);
		s_addr += 16;
		i -= 16;
	}
}
