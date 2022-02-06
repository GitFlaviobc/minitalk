/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_minitalk.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:58:32 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 12:08:37 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MINITALK_H
# define CLIENT_MINITALK_H
# include <signal.h>
# include "../libft/libft.h"
# define MASK_128 0x80

typedef enum e_status
{
	SENDING_LENGHT = 0,
	SENDING_TEXT,
	SENDING_END,
}			t_status;

typedef struct s_client
{
	char		*message;
	char		*lenght;
	size_t		msg_len;
	int			str_bit;
	int			bit_null;
	int			server_pid;
	t_status	status;
}			t_client;

int		ft_send_char(t_client *client, char *message);
void	ft_send_string_bit(t_client *client, char *message);
int		ft_send_null(t_client *client);
int		ft_end_client(t_client *client);
int		ft_error_client(t_client *client);

#endif