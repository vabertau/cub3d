/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:08:01 by vabertau          #+#    #+#             */
/*   Updated: 2023/11/15 19:26:19 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = (long)n;
	if (l == 0)
		write (fd, "0", 1);
	if (l < 0)
	{
		write(fd, "-", 1);
		l = -l;
	}
	if (l > 0)
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd((l % 10) + 48, fd);
	}
}
