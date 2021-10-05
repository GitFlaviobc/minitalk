/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:33:13 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/01 11:39:50 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_pos;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	last_pos = ft_lstlast(*lst);
	last_pos->next = new;
}
