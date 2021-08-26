/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:12:42 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/19 21:48:27 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <libgen.h>

#include "ft_utils.h"
#include "ft_display_file.h"

#define LINE_MAX_SIZE 1216

int	is_user_mode(char *s)
{
	return (ft_strlen(s) == 1 && s[0] == '-');
}

void	user_input_mode(void)
{
	int		ret;
	char	buff[LINE_MAX_SIZE + 1];

	ret = 1;
	while (ret != 0)
	{
		ret = read(STDIN_FILENO, buff, LINE_MAX_SIZE);
		buff[ret] = 0;
		ft_putstr(buff);
	}
}

void	ft_cat(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		user_input_mode();
		return ;
	}
	while (i < ac)
	{
		if (is_user_mode(av[i]))
			user_input_mode();
		else if (ft_display_file(av[i]) == -1)
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": ");
			ft_putstr(av[i]);
			ft_putstr(": No such file or directory\n");
		}
		i++;
	}
}
