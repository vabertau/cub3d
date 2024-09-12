/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:47 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/19 12:05:20 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	if (ret != NULL)
		ft_memset(ret, 0, nmemb * size);
	return (ret);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *arr;
    int i;

    arr = (int *)ft_calloc(5, sizeof(int));
    if (arr == NULL)
    {
        printf("Error: ft_calloc failed to allocate memory.\n");
        return (1);
    }

    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return (0);
}*/
