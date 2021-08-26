/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:49:17 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/07 19:28:56 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == to_find[n])
		{
			if (to_find[n] == '\0' || to_find[n + 1] == '\0')
				return (str + i - n);
			n++;
		}
		else
			n = 0;
		i++;
	}
	return (0);
}
