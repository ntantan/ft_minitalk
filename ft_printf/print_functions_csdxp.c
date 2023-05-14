/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_csdxp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:22:16 by ntan              #+#    #+#             */
/*   Updated: 2021/12/10 18:12:51 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	ft_putchar_fd(c, FD);
	return (1);
}

int	print_s(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", FD);
		return (6);
	}
	ft_putstr_fd(s, FD);
	return (ft_strlen(s));
}

int	print_d(int d)
{
	return (count_putnbr_fd(d, FD));
}

int	print_x(int x, char c)
{
	if (c == 'x')
		return (iterative_putnbr_base(x, "0123456789abcdef", 16));
	else
		return (iterative_putnbr_base(x, "0123456789ABCDEF", 16));
}

int	print_p(void *p)
{
	if (!p)
	{
		ft_putstr_fd("0x0", FD);
		return (3);
	}
	return (iterative_putnbr_p(p, "0123456789abcdef", 16));
}
