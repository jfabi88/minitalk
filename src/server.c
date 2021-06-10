/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:47:49 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/10 15:29:16 by pceccoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_count(int sign)
{
	static int	cont;
	static int	carattere;
	static int	indx;
	static char	string[100];

	cont++;
	if (sign == SIGUSR2)
	{
		carattere = carattere << 1;
		carattere += 1;
	}
	else
		carattere = carattere << 1;
	if (cont == 7)
	{
		string[indx] = carattere;
		indx++;
		if (carattere == 0)
		{
			ft_putstr_fd(string, 1);
			indx = 0;
		}
		cont = 0;
		carattere = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*piddino;
	int		count1;

	count1 = -1;
	pid = getpid();
	piddino = ft_itoa(pid);
	ft_putstr_fd(piddino, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	while (1)
		pause();
}
