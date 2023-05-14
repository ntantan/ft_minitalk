/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:42:41 by ntan              #+#    #+#             */
/*   Updated: 2022/03/11 13:19:40 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power--)
		result = result * nb;
	return (result);
}

void	signal_handler(int sig)
{
	static char				str[MAX_MSG] = {0};
	static unsigned char	temp = 0;
	static int				bit = 0;
	static int				i = 0;

	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			temp += ft_iterative_power(2, bit);
		bit++;
	}
	if (bit == 8)
	{
		str[i] = temp;
		if (str[i] == '\0')
		{
			ft_printf("%s\n", str);
			i = -1;
		}
		i++;
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			sigset;

	ft_printf("pid : %d\n", getpid());
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sigset, SIGUSR1);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
