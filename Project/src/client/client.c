/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:17:42 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 16:34:50 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_minitalk.h"

void	ft_struct_client(t_client *client, int pid, char *message)
{
	client->message = ft_strdup(message);
	if (!client->message)
		ft_error_client(client);
	client->msg_len = ft_strlen(message);
	client->lenght = ft_itoa(client->msg_len);
	client->str_bit = -1;
	client->bit_null = 0;
	client->server_pid = pid;
	client->status = SENDING_LENGHT;
}

void	ft_client_check(int pid, char *message)
{
	static t_client	client_info;

	if (client_info.server_pid == 0)
		ft_struct_client(&client_info, pid, message);
	if (client_info.status == SENDING_LENGHT)
		ft_send_char(&client_info, client_info.lenght);
	if (client_info.status == SENDING_TEXT)
		ft_send_char(&client_info, client_info.message);
	if (client_info.status == SENDING_END)
		ft_end_client(&client_info);
}

void	ft_handle_server_sigusr(int signum)
{
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
	if (argc != 3)
	{
		ft_putstr_fd("client: invalid arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, ft_handle_server_sigusr);
	signal(SIGUSR2, ft_handle_server_sigusr);
	ft_client_check(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
