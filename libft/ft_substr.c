/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:50 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/19 12:07:27 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (start >= (size_t)ft_strlen((char *)s))
	{
		ret = malloc(sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*substr;

	str = "Hello, world!";
	substr = ft_substr(str, 20, 5);
	printf("Original string: %s\n", str);
	printf("Substring: %s\n", substr);
	free(substr);
	return (0);
}
*/
