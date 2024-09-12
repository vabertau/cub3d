/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:01:20 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/19 12:18:12 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_player(t_data *data)
{
	t_player	*ply;
	char		dir;

	ply = malloc(sizeof(t_player));
	ply->x = data->p_x * TILE_SIZE + (TILE_SIZE / 2);
	ply->y = data->p_y * TILE_SIZE + (TILE_SIZE / 2);
	ply->fov = (FOV * PI) / 180;
	ply->rot = 0;
	ply->l_r = 0;
	ply->u_d = 0;
	dir = data->map2d[data->p_y][data->p_x];
	if (dir == 'N')
		ply->angle = (3 * PI) / 2;
	else if (dir == 'W')
		ply->angle = PI;
	else if (dir == 'S')
		ply->angle = PI / 2;
	else if (dir == 'E')
		ply->angle = 0;
	data->player = ply;
}

void	init_ray(t_data *data)
{
	t_ray	*ry;

	ry = malloc(sizeof(t_ray));
	ry->angle = 0;
	ry->distance = 0;
	ry->horizontal_wall = 0;
	ry->index = 0;
	ry->h_x = 0;
	ry->h_y = 0;
	ry->v_x = 0;
	ry->v_y = 0;
	data->ray = ry;
}
