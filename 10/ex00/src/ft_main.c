/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:54:40 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/19 17:17:52 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_display_file.h"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (-1);
	}
	if (ft_display_file(av[1]) == -1)
		ft_putstr("Cannot read file.\n");
	return (0);
}
