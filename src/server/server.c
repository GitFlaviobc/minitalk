/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:53:07 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/05 15:40:24 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server_minitalk.h"

void	ft_check_status(t_server *server)
{
	if (server->status == GETTING_LENGHT)
		ft_prepare_text(server);
	else if (server->status == GETTING_TEXT)
	{
		ft_print_string(server->message);
		ft_prepare_next_client(server);
	}
}

void	ft_get_bits(int signum, t_server *server)
{
	if (signum == SIGUSR1)
		server->mask = server->mask ^ (MASK_128 >> server->server_bit);
	else if (signum == SIGUSR2)
		server->mask = server->mask | (MASK_128 >> server->server_bit);
	server->server_bit++;
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static t_server	server;

	(void)context;
	if (!server.client_pid)
		ft_struct_server(&server, info->si_pid);
	ft_get_bits(signum, &server);
	if (server.server_bit == 8)
	{
		if (server.mask)
			ft_create_string(&server);
		else
			ft_check_status(&server);
		server.server_bit = 0;
		server.mask = MASK_255;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error_server(info->si_pid);
}

int	main(void)
{
	struct sigaction	sa_signal;

	ft_bzero(&sa_signal, sizeof(struct sigaction));
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
