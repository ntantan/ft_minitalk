/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:10 by ntan              #+#    #+#             */
/*   Updated: 2021/12/10 17:49:08 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	foret_de_if(char c, va_list arg_ptr)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += print_c(va_arg(arg_ptr, int));
	else if (c == 's')
		result += print_s(va_arg(arg_ptr, char *));
	else if (c == 'i' || c == 'd')
		result += print_d(va_arg(arg_ptr, int));
	else if (c == 'u')
		result += print_u(va_arg(arg_ptr, int));
	else if (c == 'x' || c == 'X')
		result += print_x(va_arg(arg_ptr, unsigned int), c);
	else if (c == 'p')
		result += print_p(va_arg(arg_ptr, void *));
	else
		result += print_percent();
	return (result);
}

int	ft_printf(const char *string, ...)
{
	int		result;
	int		i;
	va_list	arg_ptr;

	va_start(arg_ptr, string);
	result = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] != '%')
		{
			ft_putchar_fd(string[i++], FD);
			result++;
		}
		else
		{
			i++;
			result += foret_de_if(string[i], arg_ptr);
			i++;
		}
	}
	va_end(arg_ptr);
	return (result);
}
