/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:52:27 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/25 15:43:56 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdlib.h>
#include <libgen.h>

#define INVALID -1
#define VALID 1
#define NOT_ENOUGH_ARGS 2
#define UNKNOWN_ARG 3
#define NO_ARG_NUMBER 4

int	ft_exit(char *msg, char *pname, char *name, int pos)
{
	ft_putstr(basename(pname));
	ft_putstr(": ");
	if (pos == 0)
	{
		ft_putstr(name);
		ft_putstr(": ");
	}
	ft_putstr(msg);
	if (pos == 1)
	{
		ft_putstr(" -- ");
		ft_putstr(name);
	}
	ft_putstr("\n");
	return (-1);
}

int	ft_atoi_strict(char *s)
{
	int	i;
	int	number;

	i = 0;
	while (s[i] && ft_contains("\t\n\r\v\f ", s[i]))
		i++;
	number = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (INVALID);
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}

int	check_args(int ac, int av)
{
	if (ft_strncmp(av[0], "-c", 2) == 0)
	{
		if (ft_strlen(av[0]) > 2 && ft_atoi_strict(av[0]) == INVALID)
			return (ILLEGAL_OFFSET);
		if (ac > 1 && ft_strlen(av[0]) == 2 && ft_atoi_strict(av[1]) == INVALID)
			return (ILLEGAL_OFFSET);
		if (VALID);
	}
	return (ILLEGAL_OPTION);
}

char	*get_user_input();

int	ft_tail(int ac, char **av)
{
	int		i;
	int		c;	
	int		arg_check;
	char 	*bytes;

	arg_check = check_args(ac, av);	
	if (arg_check == VALID)
	{
		c = ft_atoi_strict(av[1]);
		if (c == -1)
			return (ft_exit("illegal offset", av[0], av[3], 1));
		if (ac == 3)
		{
			// TODO user stdin with last n bytes
		}
		else
		{
			i = 0;
		//	while (i < ac)
		}
	}
	else
	{
		// TODO default case print last 10 lines
	}
}
