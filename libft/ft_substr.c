/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:30 by fbonini           #+#    #+#             */
/*   Updated: 2021/06/02 10:17:05 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		ptr = (char *) malloc (1 * sizeof(char));
	else if (start + len > s_len)
		ptr = (char *) malloc ((s_len - start + 1) * sizeof(char));
	else
		ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (!(start > s_len) && s[start + i] != '\0' && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
