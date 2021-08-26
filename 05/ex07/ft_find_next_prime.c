/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:22:32 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/12 18:16:44 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	else if (nb > 2147395600)
		return (46340);
	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	max;

	if (nb == 2)
		return (1);
	else if (nb < 2 || nb % 2 == 0)
		return (0);
	i = 3;
	max = ft_sqrt(nb);
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else if (nb < 2)
		return (2);
	return (ft_find_next_prime(nb + 1));
}
