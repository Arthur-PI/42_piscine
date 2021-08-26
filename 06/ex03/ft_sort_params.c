/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:36:09 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/12 16:06:21 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_sort_argv(char **argv, int size)
{
	int		i;
	char	*tmp;

	i = 2;
	while (i < size)
	{
		if (ft_strcmp(argv[i], argv[i - 1]) < 0)
		{
			tmp = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = tmp;
			if (i > 2)
				i--;
			else
				i++;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 2)
		ft_sort_argv(argv, argc);
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
