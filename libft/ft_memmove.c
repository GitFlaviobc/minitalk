/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:18:57 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/28 15:25:06 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (src < dest)
	{
		src_cpy = src_cpy + len;
		dest_cpy = dest_cpy + len;
		while (len--)
			*(--dest_cpy) = *(--src_cpy);
	}
	else
		while (len--)
			*(dest_cpy++) = *(src_cpy++);
	return (dest);
}
