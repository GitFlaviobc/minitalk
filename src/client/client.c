/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:17:42 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/05 16:26:56 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client_minitalk.h"
// #include <stdio.h>

void	ft_struct_client(t_client *client, int pid, char *message)
{
	client->message = ft_strdup(message);
	if (!client->message)
		ft_error_client(client);
	client->msg_len = ft_strlen(message);
	client->str_bit = 0;
	client->bit_null = 0;
	client->server_pid = pid;
	client->status = SENDING_LENGHT;
}

void	ft_client_check(int pid, char *message)
{
	static t_client	client_info;
	char			*lenght;

	if (client_info.server_pid == 0)
		ft_struct_client(&client_info, pid, message);
	if (client_info.status == SENDING_LENGHT)
	{
		lenght = ft_itoa(client_info.msg_len);
		ft_send_size(&client_info, lenght);
		free(lenght);
		lenght = NULL;
	}
	if (client_info.status == SENDING_TEXT)
		ft_send_char(&client_info);
	if (client_info.status == SENDING_END)
		ft_end_client(&client_info);
}

void	ft_handle_server_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		ft_client_check(0, NULL);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("client: server ended unexpectdly.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;

	if (argc != 3)
	{
		ft_putstr_fd("client: invalid arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(&sa_client, sizeof(struct sigaction));
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = ft_handle_server_sigusr;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	ft_client_check(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
