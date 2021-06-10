/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:47:49 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/10 13:22:35 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_count_byte(char kara)
{
	int	count;

	count = 0;
	while (kara < 0)
	{
		kara = kara << 1;
		count++;
	}
	return (count);
}

void	ft_putchar_fd_mod(char *c, int fd, int byte)
{
	write(fd, c, byte);
}

void	ft_putstr_fd_mod(char *s, int fd)
{
	int	i;
	int byte;

	i = 0;
	if (fd != 0 && s != 0)
	{
		while (s[i])
		{
			if (s[i] < 0)
			{
				byte = ft_count_byte(s[i]);
				ft_putchar_fd_mod(&s[i], fd, byte);
				i += byte;
			}
			else
			{
				ft_putchar_fd_mod(&s[i], fd, 1);
				i++;
			}
		}
	}
}

void ft_count(int sign)
{
	static int cont;
	static int carattere;
	static int indx;
	static char string[100];
	
	cont++;
	printf("%d\n", carattere);
	if (sign == SIGUSR2)
	{
		carattere = carattere << 1;
		carattere += 1;
	}
	else
		carattere = carattere << 1;
	if (cont == 8)
	{
		string[indx] = carattere;
		indx++;
		if (carattere == 0)
		{
			ft_putstr_fd_mod(string, 1);
			printf("\n\n\n");
			indx = 0;
		}
		cont = 0;
		carattere = 0;
	}
}

int main(void)
{
	int pid;
	char *piddino;
	int count1;

	count1 = -1;
	pid = getpid();
	piddino = ft_itoa(pid);
	ft_putstr_fd(piddino, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	while(1)
		pause();
}