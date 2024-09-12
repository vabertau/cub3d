/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:35:52 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 18:15:19 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	exit_free_sprites(t_data *data, int code, char *message, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (data->sprites && data->sprites[i].fti)
			mlx_destroy_image(data->init, data->sprites[i].fti);
		i++;
	}
	if (data->new_image && data->new_image->img_p)
		mlx_destroy_image(data->init, data->new_image->img_p);
	mlx_destroy_window(data->init, data->win);
	mlx_destroy_display(data->init);
	printf("%s", message);
	free_all(data);
	exit(code);
}

static t_image	*load_image(t_data *data, char *path, int index)
{
	t_image	*im;

	im = malloc(sizeof(t_image));
	if (!im)
		exit_free_sprites(data, -1, "Malloc error\n", index);
	im->fti = mlx_xpm_file_to_image(data->init, path, &im->width, &im->height);
	if (!im->fti)
	{
		free(im);
		exit_free_sprites(data, -1, "mlx error\n", index);
	}
	im->gda = mlx_get_data_addr(im->fti, &im->bit_pp, & im->line_len, &im->edn);
	if (!im->gda)
	{
		mlx_destroy_image(data->init, im->fti);
		free(im);
		exit_free_sprites(data, -1, "mlx error\n", index);
	}
	return (im);
}

void	init_sprites(t_data *data)
{
	int		i;
	t_image	*loaded_img;

	i = 0;
	data->sprites = malloc(sizeof(t_image) * 4);
	if (!data->sprites)
		exit_free(data, -1, "Malloc error\n");
	while (i < 4)
	{
		loaded_img = load_image(data, data->xpm_path[i], i);
		if (loaded_img)
		{
			data->sprites[i] = *loaded_img;
			free(loaded_img);
		}
		i++;
	}
}
