/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:03:58 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 15:09:43 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_minitalk.h"

void	ft_free_msg(t_client *client)
{
	if (client->lenght)
		free(client->lenght);
	if (client->message)
		free(client->message);
}

int	ft_error_client(t_client *client)
{
	ft_putstr_fd("client: unexpected error.\n", 2);
	ft_free_msg(client);
	exit(EXIT_FAILURE);
}

int	ft_end_client(t_client *client)
{
	ft_free_msg(client);
	ft_putstr_fd("client: operation successful.\n", 1);
	exit(EXIT_SUCCESS);
}
