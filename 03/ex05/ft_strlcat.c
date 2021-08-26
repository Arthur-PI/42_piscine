/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:30:27 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/12 19:43:04 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lendst;
	unsigned int	lensrc;

	i = 0;
	lendst = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendst)
		return (lensrc + size);
	while (src[i] && i + lendst < size - 1)
	{
		dest[lendst + i] = src[i];
		i++;
	}
	dest[lendst + i] = '\0';
	return (lendst + lensrc);
}
