/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:32:01 by vabertau          #+#    #+#             */
/*   Updated: 2023/11/08 14:52:01 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*condition if pour le cas ou les string sont egales puis une seule
 * se termine: doit renvoyer 0*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n && us1[i] && us2[i] && us1[i] - us2[i] == 0)
			i++;
	if ((i > 0) && ((!us1[i] && us2[i]) || (us1[i] && !us2[i])))
		return (us1[i - 1] - us2[i - 1]);
	return (us1[i] - us2[i]);
}
