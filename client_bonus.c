/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:19:09 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/10 13:28:59 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <wchar.h>

char *ft_ctobit(char carattere)
{
	int i;
	char *ret;

	ret = malloc(sizeof(9));
	if (ret == 0)
		exit(0);
	ret[8] = 0;
	i = 7;
	while (carattere > 1)
	{
		ret[i] = (carattere % 2) + 48;
		carattere /= 2;
		i--;
	}
	ret[i] = (carattere % 2) + 48;
	i--;
	while (i >= 0)
	{
		ret[i] = 48;
		i--;
	}
	return (ret);
}

void ft_send_term(int pid)
{
	int i;

	i = 0;
	while (i < 9)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

void	ft_string_complement(char *string)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while(string[i] != 0)
	{
		if (string[i] == '0')
			string[i] = '1';
		else if (string[i] == '1')
			string[i] = '0';
		i++;
	}
	i = 7;
	while (i > 0 && flag != 1)
	{
		if (string[i] == '0')
		{
			string[i] = '1';
			flag = 1;
		}
		else 
			string[i] = '0';
		i--;
	}
}

char	*ft_ctobit_pluse(char cara)
{
	char *string;

	cara *= -1;
	string = ft_ctobit(cara);
	ft_string_complement(string);
	return (string);
}

void ft_send_signal(int pid, char *string)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (string[i])
	{
		if (string[i] < 0)
		{
			temp = ft_ctobit_pluse(string[i]);
			printf("%s\n", temp);
		}
		else
			temp = ft_ctobit(string[i]);
		j = 0;
		while (temp[j])
		{
			if (temp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	ft_send_term(pid);
}

int main(int argc, char *argv[])
{
	struct sigaction sig;
	struct sigaction old_sig;
	int pid;
	int i;
	char *string;

	ft_check_error(argc, argv);
	i = 0;
	pid = ft_atoi(argv[1]);
	string = argv[2];
	ft_send_signal(pid, string);
	//ft_send_term(pid);
	//sig.sa_handler = ft_printa2;
	//sig.sa_flags = 0;
	//sigemptyset(&sig.sa_mask);
	//sigaction(SIGUSR1, 0, &old_sig);
	//sigaction(SIGUSR1, &sig, 0);
}
