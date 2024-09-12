/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:42:18 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/19 16:33:16 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*selon l'angle du rayon et le type de mur (v/h) on recupere la bonne texture*/
static t_image	*get_texture(t_data *data)
{
	if (data->ray->horizontal_wall == 0)
	{
		if (data->ray->angle > PI / 2 && data->ray->angle < 3 * (PI / 2))
			return (&data->sprites[2]);
		else
			return (&data->sprites[3]);
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < PI)
			return (&data->sprites[1]);
		else
			return (&data->sprites[0]);
	}
}

/*on recupere la bonne texture et pour chaque pixel de la texture on affiche
le bon a l'ecran*/
static void	draw_wall(t_data *data, double t_pix, double b_pix, double wall_h)
{
	t_image	*tex;
	double	tex_x;
	int		y;
	int		color;
	int		tex_y;

	tex = get_texture(data);
	if (data->ray->horizontal_wall == 1)
		tex_x = fmod((data->ray->h_x * (tex->width / TILE_SIZE)), tex->width);
	else
		tex_x = fmod((data->ray->v_y * (tex->width / TILE_SIZE)), tex->width);
	y = t_pix;
	while (y < b_pix)
	{
		tex_y = (y - t_pix) * tex->height / wall_h;
		color = *(int *)(tex->gda + (tex_y * tex->line_len
					+ (int)tex_x * (tex->bit_pp / 8)));
		if (y < 0)
			y = 0;
		my_mlx_pixel_put(data->new_image, data->ray->index, y, color);
		y++;
	}
}

/*On recupere les couleurs du sol et du plafond et on les affiche*/
static void	draw_floor_ceiling(t_data *data, int t_pix, int b_pix)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_string_to_color(data->xpm_path[4]);
	ceiling_color = rgb_string_to_color(data->xpm_path[5]);
	y = 0;
	x = data->ray->index;
	while (y < t_pix)
	{
		my_mlx_pixel_put(data->new_image, x, y, ceiling_color);
		y++;
	}
	y = b_pix;
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data->new_image, x, y, floor_color);
		y++;
	}
}

/*Selon la distance qui nous separe du mur, on adapte la taille 
du mur a l'ecran*/
void	render_wall(t_data *data)
{
	double	wall_height;
	double	b_pix;
	double	t_pix;
	double	relative_angle;

	relative_angle = nor_angle(data->ray->angle - data->player->angle);
	data->ray->distance *= cos(relative_angle);
	wall_height = (TILE_SIZE / data->ray->distance) * ((SCREEN_WIDTH / 2)
			/ tan(data->player->fov / 2));
	b_pix = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	t_pix = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (b_pix > SCREEN_HEIGHT)
		b_pix = SCREEN_HEIGHT;
	draw_wall(data, t_pix, b_pix, wall_height);
	if (t_pix < 0)
		t_pix = 0;
	draw_floor_ceiling(data, t_pix, b_pix);
}
