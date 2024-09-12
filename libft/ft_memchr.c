/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:42:34 by vabertau          #+#    #+#             */
/*   Updated: 2023/11/08 14:53:41 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (((((unsigned char *)s)[i]) != (unsigned char)c)
			&& ((unsigned char *)s)[i] && i < n)
		i++;
	if ((((unsigned char *)s)[i]) == (unsigned char)c)
		return (&(((unsigned char *)s)[i]));
	else
		return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_my_memchr() {
    // Test case 1
    char str1[] = "hello world";
    char *result1 = ft_memchr(str1, 'w', strlen(str1));
    char *expected_result1 = &str1[6];
    assert(result1 == expected_result1);

    // Test case 2
    char str2[] = "hello world";
    char *result2 = ft_memchr(str2, 'f', strlen(str2));
    char *expected_result2 = NULL;
    assert(result2 == expected_result2);

    // Test case 3
    char str3[] = "hello world";
    char *result3 = ft_memchr(str3, 'h', strlen(str3));
    char *expected_result3 = &str3[0];
    assert(result3 == expected_result3);
}

int main() {
    test_my_memchr();
    printf("All test cases passed!\n");
    return 0;
}
*/
