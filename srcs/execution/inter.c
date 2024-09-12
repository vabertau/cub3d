/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:31:03 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/19 15:12:12 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*check de quel cote de l'axe on se dirige et ajuste le step*/
static int	positive_side_of_axis(float angle, char axis)
{
	if (axis == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	if (axis == 'y')
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
			return (1);
	}
	return (0);
}

/*recupere la premiere intersection et l'ajuste de 1 ou -1 pour
etre sur d'etre dans la bonne grille*/
static int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/*check si on a trouve un mur*/
static int	no_wall_hit(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (0);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y >= data->h_map2d || map_x >= data->w_map2d)
		return (0);
	if (data->map2d[map_y] && map_x <= ft_strlen(data->map2d[map_y]))
	{
		if (data->map2d[map_y][map_x] == '1')
			return (0);
	}
	return (1);
}

/*recupere la distance jusqu'au premier mur horizontal*/
float	get_h_inter(t_data *data)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(data->ray->angle);
	h_y = floor(data->player->y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(data->ray->angle, &h_y, &y_step, 1);
	h_x = data->player->x + (h_y - data->player->y) / tan(data->ray->angle);
	if ((positive_side_of_axis(data->ray->angle, 'y') && x_step < 0)
		|| (!(positive_side_of_axis(data->ray->angle, 'y')) && x_step > 0))
		x_step *= -1;
	while (no_wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	data->ray->h_x = h_x;
	data->ray->h_y = h_y;
	return (sqrt(pow(h_x - data->player->x, 2)
			+ pow(h_y - data->player->y, 2)));
}

/*recupere la distance jusqu'au premier mur vertical*/
float	get_v_inter(t_data *data)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(data->ray->angle);
	v_x = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(data->ray->angle, &v_x, &x_step, 0);
	v_y = data->player->y + (v_x - data->player->x) * tan(data->ray->angle);
	if ((positive_side_of_axis(data->ray->angle, 'x') && y_step < 0)
		|| (!(positive_side_of_axis(data->ray->angle, 'y')) && y_step > 0))
		y_step *= -1;
	while (no_wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	data->ray->v_x = v_x;
	data->ray->v_y = v_y;
	return (sqrt(pow(v_x - data->player->x, 2)
			+ pow(v_y - data->player->y, 2)));
}
