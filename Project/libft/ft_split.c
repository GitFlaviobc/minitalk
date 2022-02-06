/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:09 by fbonini           #+#    #+#             */
/*   Updated: 2021/05/29 18:57:26 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numb_words(char const *word, char c)
{
	size_t	numb;
	int		is_word;

	numb = 0;
	is_word = 0;
	while (*word)
	{
		if (*word != c && is_word == 0)
		{
			is_word = 1;
			numb++;
		}
		else if (is_word == 1 && *word == c)
			is_word = 0;
		word++;
	}
	return (numb);
}

size_t	ft_word_length(const char *word, char c)
{
	size_t	len;

	len = 0;
	while (word[len] && word[len] != c)
		len++;
	return (len);
}

char	*ft_make_word(const char *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_s;
	size_t	arr_len;
	size_t	word_len;
	size_t	i;

	if (s == 0)
		return (0);
	arr_len = ft_numb_words(s, c);
	arr_s = malloc(sizeof(char *) * (arr_len + 1));
	if (arr_s == 0)
		return (0);
	i = 0;
	while (i < arr_len)
	{
		word_len = ft_word_length(s, c);
		if (word_len)
		{
			arr_s[i] = ft_make_word(s, word_len);
			i++;
		}
		s = s + word_len + 1;
	}
	arr_s[i] = 0;
	return (arr_s);
}
