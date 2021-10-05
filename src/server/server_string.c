/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:40:08 by fbonini-          #+#    #+#             */
/*   Updated: 2021/10/05 13:36:53 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server_minitalk.h"

char	*ft_strjoin_first(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

char	*ft_strjoin_char(char *s1, char const s2)
{
	char	*add;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin_first(s2));
	add = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!add)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		add[i] = s1[i];
	free(s1);
	add[i++] = s2;
	add[i] = '\0';
	return (add);
}

void	ft_create_string(t_server *server)
{
	if (server->status == GETTING_LENGHT)
		server->lenght = ft_strjoin_char(server->lenght, server->mask);
	else if (server->status == GETTING_TEXT)
		server->message = ft_strjoin_char(server->message, server->mask);
}

void	ft_print_string(char *message)
{
	ft_putstr_fd("Client message: ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
}
