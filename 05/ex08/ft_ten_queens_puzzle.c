/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:09:04 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/11 10:44:33 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(char *board)
{
	int		i;

	i = 0;
	while (board[i])
		write(1, &board[i++], 1);
	write(1, "\n", 1);
}

int	is_pos_valid(char *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (board[n] == board[i]
			|| board[n] == (board[i] + (n - i))
			|| board[n] == (board[i] - (n - i)))
			return (0);
		i++;
	}
	return (1);
}

int	found_pos_rec(char *board, int n)
{
	int	i;
	int	soluces;

	i = 0;
	soluces = 0;
	while (i < 10)
	{
		board[n] = i + '0';
		if (is_pos_valid(board, n))
		{
			if (n == 9)
			{
				print_board(board);
				soluces += 1;
			}
			else
				soluces += found_pos_rec(board, n + 1);
		}
		i++;
	}
	return (soluces);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[11];

	board[10] = 0;
	return (found_pos_rec(board, 0));
}
