/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:10:15 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/24 00:34:26 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_btlines(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2d[0][i])
	{
		if (data->map2d[0][i] != '1' && data->map2d[0][i] != ' ')
			exit_free(data, -1, "Map error\n");
		i++;
	}
	i = 0;
	while (data->map2d[data->h_map2d - 1][i])
	{
		if (data->map2d[data->h_map2d - 1][i] != '1'
			&& data->map2d[data->h_map2d - 1][i] != ' ')
			exit_free(data, -1, "Map error\n");
		i++;
	}
}

void	check_mapisclosed(t_data *data, int i, int j)
{
	if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && (data->map2d[i][j + 1] == ' '))
		exit_free(data, -1, "Map error\n");
	else if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && (data->map2d[i][j + 1] == '\0'))
		exit_free(data, -1, "Map error\n");
	else if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && (data->map2d[i][j - 1] == ' '))
		exit_free(data, -1, "Map error\n");
	else if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && (data->map2d[i + 1][j] == ' '))
		exit_free(data, -1, "Map error\n");
	else if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && (ft_strlen(data->map2d[i - 1]) <= j))
		exit_free(data, -1, "Map error\n");
	else if ((data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
		|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W'
		|| data->map2d[i][j] == '0') && ((ft_strlen(data->map2d[i - 1]) > j) && data->map2d[i - 1][j] == ' '))
		exit_free(data, -1, "Map error\n");
}

void	check_rlline(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->h_map2d - 1)
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if ((j == 0) && !data->map2d[i][j])
				j++;
			else
			{
				if ((j == 0) && ((data->map2d[i][j] != '1'
						&& data->map2d[i][j] != ' ')))
					exit_free(data, -1, "Map error\n");
				if (j > 0)
					check_mapisclosed(data, i, j);
				j++;
			}
		}
		i++;
	}
}
