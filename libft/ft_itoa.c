/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:18:47 by fbonini           #+#    #+#             */
/*   Updated: 2021/10/05 14:39:49 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numblen(int numb)
{
	int	i;

	i = 0;
	if (numb == 0 || numb < 0)
		i++;
	while (numb != 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_size;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = ft_numblen(n);
	str = (char *) malloc ((n_size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[n_size] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	while (n_size-- > i)
	{
		str[n_size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
