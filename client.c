/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:02 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/20 15:57:52 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	ft_atoi(char *str)
{
	int	rez;

	rez = 0;
	if (*str == '-')
		return (ft_printf("ERROR: pid can t be negative!\n"), 1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			rez = rez * 10 + *str++ - '0';
		else
			return (ft_printf("ERROR: pid can t include letters!\n"), 1);
	}
	if (!rez)
		return (ft_printf("ERROR!\n", 1));
	return (rez);
}

void	send_message(int pid, char c)
{
	int	n;

	n = 8;
	while (n--)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1))
			{
				ft_printf("Error pid dosen t match\n");
				return ;
			}
		}
		else if (kill(pid, SIGUSR2))
		{
			ft_printf("Error pid dosen t match\n");
			return ;
		}
		c >>= 1;
		pause();
	}
}

void	recived(int sig)
{
	(void)sig;
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	str = argv[2];
	if (argc != 3)
		return (ft_printf("Error!\n"), 1);
	signal(SIGUSR1, recived);
	pid = ft_atoi(argv[1]);
	while (*str)
		send_message(pid, *str++);
	send_message(pid, 0);
	ft_printf("message has arrived\n");
	return (0);
}
