/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:15:20 by ratavare          #+#    #+#             */
/*   Updated: 2023/06/20 18:45:35 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char a)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if (a & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(150);
	}
}

void	send_len(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit <= 31)
	{
		if (len & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(150);
	}
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		printf("Message received by the server.\n");
}

int	main(int argc, char	**argv)
{
	int	pid;
	int	i;
	int	len;

	i = 0;
	if (argc != 3)
		ft_printf("Invalid argument number.\nUsage: ./client 'PID' 'message'\n");
	else
	{
		pid = ft_atoi(argv[1]);
		len = ft_strlen(argv[2]);
		signal(SIGUSR1, handle_sig);
		send_len(pid, len);
		while (argv[2][i])
			send_sig(pid, argv[2][i++]);
		send_sig(pid, '\0');
	}
	return (0);
}
