/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:10:06 by ratavare          #+#    #+#             */
/*   Updated: 2023/04/21 22:38:43 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_len(int sig, siginfo_t *info, void *context);
void	handle_sig(int sig, siginfo_t *info, void *context);

typedef struct s_var
{
	struct sigaction	sa;
	int					len;
	int					cpid;
	char				*str;
}	t_var;

static t_var	g_var;

void	handle_sig(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		c;
	static int		i;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else
		c |= 0 << bit;
	bit++;
	if (bit == 8)
	{
		g_var.str[i++] = c;
		if (c == '\0')
		{
			write(1, g_var.str, g_var.len);
			free(g_var.str);
			g_var.len = 0;
			g_var.sa.sa_sigaction = recieve_len;
			i = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
}

void	recieve_len(int sig, siginfo_t *info, void *context)
{
	static int	bit;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_var.len |= 1 << bit;
	else
		g_var.len |= 0 << bit;
	bit++;
	if (bit == 32)
	{
		g_var.str = malloc(g_var.len * sizeof(char) + 1);
		g_var.sa.sa_sigaction = handle_sig;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
		ft_printf("Invalid argument number.\nUsage: ./server\n");
	else
	{
		pid = getpid();
		ft_printf("Server PID: %d\nWaiting for a message...\n", pid);
		g_var.sa.sa_sigaction = recieve_len;
		g_var.sa.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &g_var.sa, 0);
			sigaction(SIGUSR2, &g_var.sa, 0);
			pause();
		}
	}
	return (0);
}
