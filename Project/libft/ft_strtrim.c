/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:28 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/29 15:39:33 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substring;
	size_t	s1_len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == 0)
	{
		substring = malloc (1 * sizeof(char));
		if (!substring)
			return (0);
		substring[0] = '\0';
		return (substring);
	}
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	substring = ft_substr((char *)s1, 0, s1_len + 1);
	return (substring);
}
