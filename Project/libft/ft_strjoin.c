/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:12 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/02 10:21:14 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *) malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			ptr[i] = *s1++;
		else
			ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
