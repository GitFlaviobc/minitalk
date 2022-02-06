/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:59:06 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 15:09:50 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_minitalk.h"

void	ft_reset_bit(t_client *client)
{
	if (client->status == SENDING_TEXT)
		client->status = SENDING_END;
	else if (client->status == SENDING_LENGHT)
	{
		client->str_bit = -1;
		client->bit_null = 0;
		client->status = SENDING_TEXT;
	}
}

int	ft_send_null(t_client *client)
{
	client->str_bit--;
	if (client->bit_null == 8)
	{
		ft_reset_bit(client);
		return (0);
	}
	if (kill(client->server_pid, SIGUSR1) == -1)
		ft_error_client(client);
	client->bit_null++;
	return (0);
}

void	ft_send_string_bit(t_client *client, char *str)
{
	if (str[client->str_bit / 8] & (MASK_128 >> (client->str_bit % 8)))
	{
		if (kill(client->server_pid, SIGUSR2) == -1)
			ft_error_client(client);
	}
	else if (kill(client->server_pid, SIGUSR1) == -1)
		ft_error_client(client);
}

int	ft_send_char(t_client *client, char *message)
{
	client->str_bit++;
	if (message[client->str_bit / 8] == '\0')
		ft_send_null(client);
	else
		ft_send_string_bit(client, message);
	return (0);
}
