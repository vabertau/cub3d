/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:28:03 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/23 14:08:35 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*skips instructions to get to the map*/
void	skip_instr(t_data *data, int *i)
{
	int	count_instr;

	count_instr = 0;
	while (data->map[*i])
	{
		if (!data->map[*i][0])
			*i = *i + 1;
		else if (!ft_strncmp(data->map[*i], "NO", 2)
			|| !ft_strncmp(data->map[*i], "SO", 2) || !ft_strncmp(data->map[*i],
				"WE", 2) || !ft_strncmp(data->map[*i], "EA", 2)
			|| !ft_strncmp(data->map[*i], "F", 1) || !ft_strncmp(data->map[*i],
				"C", 1))
		{
			count_instr++;
			*i = *i + 1;
		}
		if (count_instr == 6)
			break ;
	}
	while (ft_strncmp(data->map[*i], "", 1) == 0)
	{
		*i = *i + 1;
		if (!data->map[*i])
			exit_free(data, -1, "Map error\n");
	}
}

static void	get_h_w_map2d(t_data *data)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	skip_instr(data, &i);
	height = 0;
	width = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > width)
			width = ft_strlen(data->map[i]);
		height++;
		i++;
	}
	data->h_map2d = height;
	data->w_map2d = width;
}

static void	get_player_pos_in_map2d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
				|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W')
			{
				data->p_y = i;
				data->p_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_map2d(t_data *data)
{
	int		i;
	int		j;
	char	**map2d;

	i = 0;
	skip_instr(data, &i);
	get_h_w_map2d(data);
	map2d = malloc((data->h_map2d + 1) * sizeof(char *));
	if (!map2d)
		return ;
	j = 0;
	while (data->map[i])
	{
		map2d[j] = ft_strdup(data->map[i]);
		i++;
		j++;
	}
	map2d[j] = NULL;
	data->map2d = map2d;
	get_player_pos_in_map2d(data);
}
