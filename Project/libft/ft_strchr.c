/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:10 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/01 16:33:46 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*u_src;
	unsigned char	u_c;

	u_src = (unsigned char *)src;
	u_c = (unsigned char)c;
	if (*u_src == u_c)
		return ((char *)src);
	while (*u_src)
	{
		if (*u_src == u_c)
			return ((char *)u_src);
		u_src++;
	}
	if (u_c == '\0')
		return ((char *)u_src);
	return (0);
}
