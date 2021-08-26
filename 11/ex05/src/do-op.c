/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:09:53 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/24 16:59:35 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MOD_ERROR "Stop : modulo by zero"
#define DIV_ERROR "Stop : division by zero"

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(char *n);
int		ft_strlen(char *s);
int		ft_getindex(char *s, char c);
int		sum(int a, int b);
int		sub(int a, int b);
int		div(int a, int b);
int		mul(int a, int b);
int		mod(int a, int b);

void	calc(int a, int b, int(*f)(int, int))
{
	int	res;

	if (b == 0 && f == &div)
		ft_putstr(DIV_ERROR);
	else if (b == 0 && f == &mod)
		ft_putstr(MOD_ERROR);
	else
	{
		res = (*f)(a, b);
		ft_putnbr(res);
	}
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		index;
	int		(*ops_func[5])(int, int);
	char	*ops;

	if (ac != 4)
		return (1);
	ops_func[0] = &sum;
	ops_func[1] = &sub;
	ops_func[2] = &mul;
	ops_func[3] = &div;
	ops_func[4] = &mod;
	ops = "+-*/%";
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	index = ft_getindex(ops, *av[2]);
	if (index != -1)
		calc(a, b, ops_func[ft_getindex(ops, *av[2])]);
	else
		ft_putstr("0\n");
}
