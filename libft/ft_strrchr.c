/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:25 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/28 18:56:45 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t			src_len;
	unsigned char	*u_src;
	unsigned char	u_c;

	u_src = (unsigned char *)src;
	u_c = (unsigned char)c;
	src_len = ft_strlen(src) + 1;
	while (src_len--)
	{
		if (u_src[src_len] == u_c)
			return ((char *)u_src + src_len);
	}
	return (0);
}
