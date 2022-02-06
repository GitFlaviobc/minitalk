/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:24 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/28 15:29:42 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	str2_len;

	str2_len = ft_strlen(str2);
	if (str2_len == 0)
		return ((char *)str1);
	while (*str1 && len >= str2_len)
	{
		if (!ft_strncmp(str1, str2, str2_len))
			return ((char *)str1);
		str1++;
		len--;
	}
	return (0);
}
