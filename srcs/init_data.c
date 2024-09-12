/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:17:37 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 18:14:03 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_xpm_path(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->xpm_path[i] = NULL;
		i++;
	}
}

/* Init data : aim is to set to null or -1 in order to keep track
of if an element was malloc and need to be freed*/
void	init_data(t_data *data)
{
	init_xpm_path(data);
	data->win = NULL;
	data->sprites = NULL;
	data->init = NULL;
	data->map = NULL;
	data->new_image = NULL;
	data->map2d = NULL;
	data->player = NULL;
	data->ray = NULL;
}
