/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:14:44 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/18 12:07:24 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_contains(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_tablen(char *s, char *seps)
{
	int		i;
	int		cpt;
	char	flag;

	i = 0;
	cpt = 0;
	flag = 1;
	while (s[i])
	{
		if (ft_contains(seps, s[i]))
		{
			if (flag == 0)
				cpt++;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 0)
		cpt++;
	return (cpt);
}

char	*get_string(char *s, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(n + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_split_comp(char *str, char *charset, char **tab)
{
	int	i;
	int	flag;
	int	w_start;

	i = 0;
	flag = 1;
	w_start = 0;
	while (str[i])
	{
		if (ft_contains(charset, str[i]))
		{
			if (flag == 0)
				*(tab++) = get_string(str + w_start, i - w_start);
			flag = 1;
			w_start = i + 1;
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 0)
		*(tab++) = get_string(str + w_start, i - w_start);
}

char	**ft_split(char *str, char *charset)
{
	int		tablen;
	char	*tmp;
	char	**tab;

	tablen = ft_tablen(str, charset);
	tab = malloc((tablen + 1) * sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	tmp = NULL;
	ft_split_comp(str, charset, tab);
	tab[tablen] = 0;
	return (tab);
}
