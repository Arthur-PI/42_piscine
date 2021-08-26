/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:59:58 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/09 19:34:14 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
		if (tab[(int)s[i]] || s[i] == '+' || s[i] == '-' || s[i] < 33 )
			return (-1);
		tab[(int)s[i]] = 1;
		i++;
	}
	if (i < 2)
		return (-1);
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

int	ft_isspace(char c)
{
	if (find_char("\t\n\r\v\f ", c) == -1)
		return (0);
	return (1);
}

void	ft_atoi_base_real(char *str, char *base, int b_size, int *n)
{
	int		i;
	int		start;
	char	is_negative;
	int		p;

	i = -1;
	start = 0;
	is_negative = 1;
	while (str[++i])
	{
		if (start == 0 && str[i] == '-')
			is_negative *= -1;
		else if (find_char(base, str[i]) >= 0)
			start++;
		else if (start != 0 || str[i] != '+')
			break ;
	}
	p = 1;
	start = i - start;
	while (--i >= start)
	{
		*n += find_char(base, str[i]) * p;
		p *= b_size;
	}
	*n *= is_negative;
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_size;
	int	i;

	while (str[0] && ft_isspace(str[0]))
		str++;
	i = 0;
	b_size = check_base(base);
	if (b_size == -1)
		return (0);
	ft_atoi_base_real(str, base, b_size, &i);
	return (i);
}
