/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:52:22 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/06 10:57:29 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	char_to_lower(char *c)
{
	if (c[0] >= 'A' && c[0] <= 'Z')
		c[0] += 32;
}

void	char_to_upper(char *c)
{
	if (c[0] >= 'a' && c[0] <= 'z')
		c[0] -= 32;
}

int	is_separator(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
		return (1);
	return (0);
}	

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	is_first;

	is_first = 1;
	i = 0;
	while (str[i])
	{
		if (is_first)
		{
			char_to_upper(str + i);
			is_first = 0;
		}
		else
			char_to_lower(str + i);
		if (is_separator(str[i]))
			is_first = 1;
		i++;
	}
	return (str);
}
