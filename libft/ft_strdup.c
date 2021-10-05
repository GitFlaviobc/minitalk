/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:29 by fbonini           #+#    #+#             */
/*   Updated: 2021/10/05 13:59:29 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = (char *) malloc (len * sizeof(char));
	if (ptr)
	{
		ft_strlcpy(ptr, str, len);
		return (ptr);
	}
	return (0);
}
