/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:58:35 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/23 17:32:02 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_window(t_data *data)
{
	exit_free(data, 0, "You quit cub3d !\n");
	return (0);
}

static int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == LEFT)
		data->player->rot = -1;
	else if (keycode == RIGHT)
		data->player->rot = 1;
	else if (keycode == A)
		data->player->l_r = -1;
	else if (keycode == D)
		data->player->l_r = 1;
	else if (keycode == S)
		data->player->u_d = -1;
	else if (keycode == W)
		data->player->u_d = 1;
	return (0);
}

static int	ft_key_release(int keycode, t_data *data)
{
	(void)keycode;
	data->player->rot = 0;
	data->player->l_r = 0;
	data->player->u_d = 0;
	return (0);
}

static int	game_loop(t_data *data)
{
	move_player(data, 0, 0);
	cast_rays(data);
	mlx_put_image_to_window(data->init, data->win, data->new_image->img_p, 0,
		0);
	return (0);
}

int	ft_hook(t_data data)
{
	mlx_loop_hook(data.init, &game_loop, &data);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &ft_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &ft_key_release, &data);
	return (0);
}
