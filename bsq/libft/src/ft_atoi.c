/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:36:33 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/09 19:03:13 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	char	*s;
	int		i;

	s = "\t\n\r\v\f ";
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	n;
	char	is_negative;

	i = 0;
	n = 0;
	is_negative = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (n == 0 && str[i] == '-')
			is_negative *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + str[i] - 48;
		else if (str[i] != '+' || n != 0)
			break ;
		i++;
	}
	return (is_negative * n);
}
