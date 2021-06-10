/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:50:31 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/10 12:16:01 by pceccoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_sigaction
{
	void		(*handler)();
	sigset_t	sa_mask;
	int			sa_flags;
}				t_sigaction;

/* utils.c */

char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/* error */

void	ft_check_error(int argc, char *argv[]);

#endif
