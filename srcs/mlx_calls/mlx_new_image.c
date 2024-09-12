/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:25:44 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/19 13:29:54 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	new_image(t_data *data)
{
	t_image	*img;
	char	*tp;

	img = malloc(sizeof(t_image));
	if (!img)
		exit_free(data, -1, "Malloc error\n");
	img->img_p = mlx_new_image(data->init, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img_p)
	{
		free(img);
		exit_free(data, -1, "MLX error\n");
	}
	tp = mlx_get_data_addr(img->img_p, &img->bit_pp, &img->line_len, &img->edn);
	img->gda = tp;
	if (!img->gda)
	{
		mlx_destroy_image(data->init, img->img_p);
		free(img);
		exit_free(data, -1, "MLX error\n");
	}
	data->new_image = img;
}
