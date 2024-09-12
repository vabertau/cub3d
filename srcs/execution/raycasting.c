/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:07:34 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/19 16:05:27 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*s'assure que l'angle est entre 0 et 2PI*/
double	nor_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

/*Pour chaque rayon, on recupere la distance qui nous separe d'un mur
et on affiche le mur*/
void	cast_rays(t_data *data)
{
	float	h_inter;
	float	v_inter;
	int		ray_nb;

	ray_nb = 0;
	data->ray->angle = data->player->angle - (data->player->fov / 2);
	data->ray->angle = nor_angle(data->ray->angle);
	while (ray_nb < SCREEN_WIDTH)
	{
		data->ray->horizontal_wall = 0;
		h_inter = get_h_inter(data);
		v_inter = get_v_inter(data);
		if (v_inter <= h_inter)
			data->ray->distance = v_inter;
		else
		{
			data->ray->distance = h_inter;
			data->ray->horizontal_wall = 1;
		}
		data->ray->index = ray_nb;
		render_wall(data);
		ray_nb++;
		data->ray->angle += (data->player->fov / SCREEN_WIDTH);
		data->ray->angle = nor_angle(data->ray->angle);
	}
}
