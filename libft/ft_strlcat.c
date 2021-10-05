/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:14 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/01 17:09:14 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	hold;

	dest_len = 0;
	while (dest_len < len && dest[dest_len] != '\0')
		dest_len++;
	src_len = ft_strlen(src);
	if (dest_len < len)
	{
		hold = dest_len;
		while (dest_len < len - 1 && *src != '\0')
			*(dest + dest_len++) = *src++;
		*(dest + dest_len) = '\0';
		dest_len = hold;
	}
	return (dest_len + src_len);
}
