/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:14:42 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/17 22:45:52 by apigeon          ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		lensrc;
	char	*new;
	int		i;

	lensrc = ft_strlen(src);
	new = malloc(lensrc + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < lensrc)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
