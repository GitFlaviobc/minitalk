/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_minitalk.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:58:32 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/04 17:21:58 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MINITALK_H
# define SERVER_MINITALK_H
# include <signal.h>
# include "../libft/libft.h"
# define MASK_128 0x80
# define MASK_255 0xFF

typedef enum e_status
{
	GETTING_LENGHT = 0,
	GETTING_TEXT,
}			t_status;

typedef struct s_server
{
	char		mask;
	char		*lenght;
	char		*message;
	int			server_bit;
	int			msg_len;
	int			client_pid;
	t_status	status;
}			t_server;

void	ft_struct_server(t_server *server, int pid);
void	ft_prepare_text(t_server *server_info);
void	ft_prepare_next_client(t_server *server_info);
void	ft_create_string(t_server *server_info);
void	ft_print_string(char *message);
void	ft_error_server(int pid);

#endif