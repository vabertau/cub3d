/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:58:38 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/19 13:11:41 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
sets data->mlx_init = mlx_init.
It sets up the necessary data intovoid *mlx_init for the Minilibx
to function


Creates a new window o the screen with a specified width, height and title.
*/
void	init_window(t_data *data)
{
	data->init = mlx_init();
	if (data->init == NULL)
		exit_free(data, -1, "MLX error\n");
	data->win = mlx_new_window(data->init, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3d");
	if (data->win == NULL)
		exit_free(data, -1, "MLX error\n");
}
