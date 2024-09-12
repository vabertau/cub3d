/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:22:56 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/23 11:47:31 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*recupere la couleur dans la map et la convertit en int*/
int	rgb_string_to_color(const char *rgb_str)
{
	int		r;
	int		g;
	int		b;
	char	**dest;

	dest = ft_split(rgb_str, ',');
	r = ft_atoi(dest[0]);
	g = ft_atoi(dest[1]);
	b = ft_atoi(dest[2]);
	free_tab(dest);
	return ((r << 16) | (g << 8) | b);
}

/*ajoute a l'image le pixel aux coordonnees (x,y)*/
void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->gda
		+ (y * image->line_len + x * (image->bit_pp / 8));
	*(unsigned int *)dst = color;
}

int	return_dir(double move)
{
	int	dir;

	if (move > 0)
		dir = 1;
	else if (move < 0)
		dir = -1;
	else
		dir = 0;
	return (dir);
}
