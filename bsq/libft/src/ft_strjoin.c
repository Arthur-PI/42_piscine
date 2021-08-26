/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:08:39 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/18 15:19:24 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[n] = src[i];
		i++;
		n++;
	}
	return (n);
}

char	*get_empty_string(void)
{
	char	*s;

	s = malloc(1);
	s[0] = 0;
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;
	int		lenconcat;
	int		i;
	int		j;

	if (size == 0)
		return (get_empty_string());
	i = 0;
	lenconcat = (ft_strlen(sep) * (size - 1)) + 1;
	while (i < size)
		lenconcat += ft_strlen(strs[i++]);
	concat = malloc(lenconcat);
	if (concat == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i != 0)
			j = ft_strcpy(concat, sep, j);
		j = ft_strcpy(concat, strs[i++], j);
	}
	concat[j] = '\0';
	return (concat);
}
