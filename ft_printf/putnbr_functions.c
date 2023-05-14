/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:07:19 by ntan              #+#    #+#             */
/*   Updated: 2021/12/10 18:42:51 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_putnbr_fd(int n, int fd)
{
	char			res[200];
	unsigned int	quotient;
	unsigned int	reste;
	size_t			i;

	i = 0;
	if (n < 0)
		quotient = -n;
	else
		quotient = n;
	while (quotient != 0)
	{
		reste = quotient % 10;
		quotient = quotient / 10;
		res[i++] = reste + '0';
	}
	if (n < 0)
		res[i++] = '-';
	if (n == 0)
		res[i++] = '0';
	quotient = i;
	while (i-- > 0)
		write(fd, &res[i], 1);
	return (quotient);
}

int	iterative_putnbr_p(void *n, char *base, int size)
{
	char				res[200];
	unsigned long int	quotient;
	unsigned long int	reste;
	size_t				i;

	i = 0;
	quotient = (unsigned long int) n;
	while (quotient != 0)
	{
		reste = quotient % size;
		quotient = quotient / size;
		res[i++] = base[reste];
	}
	ft_putchar_fd('0', FD);
	ft_putchar_fd('x', FD);
	quotient = i;
	while (i-- > 0)
		write(FD, &res[i], 1);
	return (quotient + 2);
}

int	iterative_putnbr_base(int n, char *base, int size)
{
	char			res[200];
	unsigned int	quotient;
	unsigned int	reste;
	size_t			i;

	i = 0;
	quotient = n;
	while (quotient != 0)
	{
		reste = quotient % size;
		quotient = quotient / size;
		res[i++] = base[reste];
	}
	if (n == 0)
		res[i++] = '0';
	quotient = i;
	while (i-- > 0)
		write(FD, &res[i], 1);
	return (quotient);
}
