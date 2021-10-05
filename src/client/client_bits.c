/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:59:06 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/05 16:14:28 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client_minitalk.h"
#include <stdio.h>
// #include <stdlib.h>

int	ft_send_null(t_client *client)
{
	if (client->bit_null++ != 8)
	{
		if (kill(client->server_pid, SIGUSR1) == -1)
			ft_error_client(client);
		return (1);
	}
	return (0);
}

int	ft_send_string_bit(t_client *client, char *str)
{
	if (str[client->str_bit / 8])
	{
		if (str[client->str_bit / 8] & (MASK_128 >> (client->str_bit % 8)))
		{
			if (kill(client->server_pid, SIGUSR2) == -1)
				ft_error_client(client);
		}
		else if (kill(client->server_pid, SIGUSR1) == -1)
			ft_error_client(client);
		client->str_bit++;
		return (1);
	}
	return (0);
}

void	ft_reset_bit(t_client *client)
{
	if (client->status == SENDING_TEXT)
		client->status = SENDING_END;
	else if (client->status == SENDING_LENGHT)
	{
		client->str_bit = 0;
		client->bit_null = 0;
		client->status = SENDING_TEXT;
	}
}

int	ft_send_char(t_client *client)
{
	if (!ft_send_string_bit(client, client->message))
	{
		if (!ft_send_null(client))
			ft_reset_bit(client);
	}
	return (0);
}

int	ft_send_size(t_client *client, char *lenght)
{
	// char	*lenght;

	// lenght = NULL;
	// if (lenght)
	// 	free(lenght);
	// lenght = ft_itoa(client->msg_len);
	if (!ft_send_string_bit(client, lenght))
	{
		if (!ft_send_null(client))
			ft_reset_bit(client);
	}
	// free(lenght);
	// lenght = NULL;
	return (0);
}
