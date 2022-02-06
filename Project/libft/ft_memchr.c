/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:18:52 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/27 19:32:25 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	const unsigned char	*src_srch;

	src_srch = ((const unsigned char *)src);
	while (len)
	{
		if (*src_srch == (unsigned char)c)
			return ((void *)src_srch);
		src_srch++;
		len--;
	}
	return (0);
}
