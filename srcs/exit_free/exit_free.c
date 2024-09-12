/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:13:04 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 18:13:16 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_map2d(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map2d)
		return ;
	while (i < data->h_map2d)
	{
		free(data->map2d[i]);
		i++;
	}
	free(data->map2d);
}

void	free_xpm_paths(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->xpm_path[i] != NULL)
			free(data->xpm_path[i]);
		i++;
	}
}

void	free_all(t_data *data)
{
	free_xpm_paths(data);
	if (data->sprites)
		free(data->sprites);
	free_map(data);
	free_map2d(data);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->new_image)
		free(data->new_image);
	free(data->init);
}

void	exit_free(t_data *data, int exit_code, char *message)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->sprites && data->sprites[i].fti)
			mlx_destroy_image(data->init, data->sprites[i].fti);
		i++;
	}
	if (data->new_image && data->new_image->img_p)
		mlx_destroy_image(data->init, data->new_image->img_p);
	if (data->win)
		mlx_destroy_window(data->init, data->win);
	if (data->init)
		mlx_destroy_display(data->init);
	printf("%s", message);
	free_all(data);
	exit(exit_code);
}
