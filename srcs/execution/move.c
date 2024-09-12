/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:03:50 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/23 16:08:57 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*change la direction du joueur*/
static void	rotate_player(t_data *data)
{
	if (data->player->rot == 1)
	{
		data->player->angle += R_SPEED;
		if (data->player->angle > 2 * PI)
			data->player->angle -= 2 * PI;
	}
	else if (data->player->rot == -1)
	{
		data->player->angle -= R_SPEED;
		if (data->player->angle < 0)
			data->player->angle += 2 * PI;
	}
}

/*verifie si la nouvelle position du joueur serait un mur,
l'update si c'est pas le cas*/
static void	move_if_no_wall(t_data *data, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;
	int		dir;

	new_x = roundf(data->player->x + move_x);
	new_y = roundf(data->player->y + move_y);
	dir = return_dir(move_x);
	map_grid_x = ((new_x + (10 * dir)) / TILE_SIZE);
	dir = return_dir(move_y);
	map_grid_y = ((new_y + (10 * dir)) / TILE_SIZE);
	if (data->map2d[map_grid_y][map_grid_x] != '1'
		&& (data->map2d[data->player->y / TILE_SIZE][map_grid_x] != '1')
		&& (data->map2d[map_grid_y][data->player->x / TILE_SIZE] != '1'))
	{
		data->player->x = new_x;
		data->player->y = new_y;
	}
}

/*maj la position du player si on appuie sur une touche
(sauf si un mur nous bloque)*/

void	move_player(t_data *data, double move_x, double move_y)
{
	rotate_player(data);
	if (data->player->u_d == 1)
	{
		move_x = cos(data->player->angle) * P_SPEED;
		move_y = sin(data->player->angle) * P_SPEED;
	}
	if (data->player->u_d == -1)
	{
		move_x = -cos(data->player->angle) * P_SPEED;
		move_y = -sin(data->player->angle) * P_SPEED;
	}
	if (data->player->l_r == 1)
	{
		move_x = -sin(data->player->angle) * P_SPEED;
		move_y = cos(data->player->angle) * P_SPEED;
	}
	if (data->player->l_r == -1)
	{
		move_x = sin(data->player->angle) * P_SPEED;
		move_y = -cos(data->player->angle) * P_SPEED;
	}
	move_if_no_wall(data, move_x, move_y);
}
