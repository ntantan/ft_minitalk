/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:37:23 by ntan              #+#    #+#             */
/*   Updated: 2022/03/11 13:19:47 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0' && nptr[i])
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

void	sender(size_t i, int bit, char **av)
{
	while (i <= ft_strlen(av[2]))
	{
		bit = 0;
		while (bit < 8)
		{
			if (av[2][i] >> bit & 1)
			{
				kill(ft_atoi(av[1]), SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(ft_atoi(av[1]), SIGUSR2);
				usleep(100);
			}
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		bit;

	bit = 0;
	i = 0;
	if (ac == 3)
	{
		if (ft_strlen(av[2]) < MAX_MSG)
			sender(i, bit, av);
	}
	return (0);
}
