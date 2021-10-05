/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:16 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/02 10:08:25 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	src_len;

	if (src == 0 || dest == 0)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < len)
		ft_memcpy(dest, src, src_len + 1);
	else if (len != 0)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
	}
	return (src_len);
}
