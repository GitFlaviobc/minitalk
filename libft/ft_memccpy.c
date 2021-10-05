/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:18:50 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/27 19:24:45 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	chr;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	chr = ((unsigned char)c);
	dest_cpy = ((unsigned char *)dest);
	src_cpy = ((unsigned char *)src);
	i = 0;
	if (dest == src)
		return (0);
	while (i < len)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == chr)
			return (&dest_cpy[i + 1]);
		i++;
	}
	return (0);
}
