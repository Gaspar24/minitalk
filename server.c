/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:48:12 by msacaliu          #+#    #+#             */
/*   Updated: 2024/02/23 12:20:43 by msacaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

t_sig	g_sig = {0, 0};

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
}

void	handle_signal(int bit, siginfo_t *info, void *s)
{
	(void)s;
	bit = (bit == SIGUSR1) & 1;
	g_sig.byte |= bit << g_sig.i++;
	if (g_sig.i == 8)
	{
		if (g_sig.byte)
			ft_printf("%c", g_sig.byte);
		else
			ft_printf("\n");
		g_sig.byte = 0;
		g_sig.i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	usr1;
	struct sigaction	usr2;

	usr1.sa_sigaction = handle_signal;
	usr1.sa_flags = SA_SIGINFO;
	usr2.sa_sigaction = handle_signal;
	usr2.sa_flags = SA_SIGINFO;
	print_pid();
	sigaction(SIGUSR1, &usr1, NULL);
	sigaction(SIGUSR2, &usr2, NULL);
	while (1)
		pause();
	return (0);
}
