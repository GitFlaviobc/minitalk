/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:33:32 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/01 11:40:35 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = ft_calloc(1, sizeof(t_list));
	if (new_element == 0)
		return (0);
	new_element->content = content;
	new_element->next = 0;
	return (new_element);
}
