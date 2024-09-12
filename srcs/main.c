/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:04:24 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/19 13:12:25 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	init_data(&data);
	parser(&data, argc, argv);
	init_window(&data);
	init_sprites(&data);
	new_image(&data);
	ft_hook(data);
	mlx_loop(data.init);
	return (0);
}
