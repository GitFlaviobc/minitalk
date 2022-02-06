/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:17:11 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/06 15:09:56 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_minitalk.h"

void	ft_error_server(int pid)
{
	ft_putstr_fd("server: unexpected error.\n", 2);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}
