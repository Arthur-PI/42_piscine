/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:55:30 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/18 15:20:15 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if (tab[(int)s[i]] || s[i] == '+' || s[i] == '-' || s[i] < 33)
			return (0);
		tab[(int)s[i]] = 1;
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	find_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_dec_to_base(long nbr, char *buff, char *base, int b_size)
{
	int				i;
	int				j;
	char			tmp;

	if (nbr < 0)
	{
		nbr = -nbr;
		*(buff++) = '-';
	}
	i = 0;
	if (nbr == 0)
		buff[i++] = base[0];
	while (nbr != 0)
	{
		buff[i++] = base[nbr % b_size];
		nbr /= b_size;
	}
	j = 0;
	buff[i--] = '\0';
	while (j < i)
	{
		tmp = buff[j];
		buff[j++] = buff[i];
		buff[i--] = tmp;
	}
}

int	ft_base_to_dec(char *nbr, char *base, int len_base)
{
	long	n;

	n = 0;
	while (*nbr && find_char(base, *nbr) != -1)
	{
		n *= len_base;
		n += find_char(base, *nbr);
		nbr++;
	}
	return (n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		sign;
	long		int_nbr;
	char		*res;

	sign = 1;
	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	while (find_char("\t\n\r\v\f ", *nbr) != -1)
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	int_nbr = ft_base_to_dec(nbr, base_from, check_base(base_from)) * sign;
	res = malloc(50);
	ft_dec_to_base(int_nbr, res, base_to, check_base(base_to));
	return (res);
}
