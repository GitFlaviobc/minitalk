/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:48:55 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 15:10:06 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_minitalk.h"

void	ft_struct_server(t_server *server, int pid)
{
	server->mask = MASK_255;
	server->server_bit = 0;
	server->client_pid = pid;
	server->msg_len = 0;
	server->lenght = NULL;
	server->message = NULL;
	server->status = GETTING_LENGHT;
}

void	ft_prepare_text(t_server *server)
{
	server->msg_len = ft_atoi(server->lenght);
	free(server->lenght);
	server->status = GETTING_TEXT;
	server->message = ft_calloc(server->msg_len + 1, sizeof(char));
}

void	ft_prepare_next_client(t_server *server)
{
	free(server->message);
	server->status = GETTING_LENGHT;
	server->client_pid = 0;
}
