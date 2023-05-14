/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:10:33 by ntan              #+#    #+#             */
/*   Updated: 2021/12/10 18:32:03 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FD 1

int		count_putnbr_fd(int n, int fd);
int		iterative_putnbr_p(void *n, char *base, int size);
int		iterative_putnbr_base(int n, char *base, int size);
int		print_c(char c);
int		print_s(char *s);
int		print_d(int d);
int		print_x(int x, char c);
int		print_p(void *p);
int		print_u(int u);
int		print_percent(void);
int		ft_printf(const char *string, ...);
int		foret_de_if(char c, va_list arg_ptr);

size_t	ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif