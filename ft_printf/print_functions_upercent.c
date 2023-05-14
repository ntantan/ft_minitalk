/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_upercent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:23:22 by ntan              #+#    #+#             */
/*   Updated: 2021/12/10 18:37:01 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(int u)
{
	return (iterative_putnbr_base(u, "0123456789", 10));
}

int	print_percent(void)
{
	ft_putchar_fd('%', FD);
	return (1);
}
