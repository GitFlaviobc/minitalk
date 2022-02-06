/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:18:56 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/02 09:49:40 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_cpy;
	unsigned const char	*src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	if (dest == src)
		return (dest);
	while (len-- > 0)
	{
		*dest_cpy++ = *src_cpy++;
	}
	return (dest);
}
