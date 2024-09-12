/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:23:52 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/24 00:35:32 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* Checks if each char is 0 1 or N S E W and that there is only one of NSEW*/
void	check_mapcomponents(t_data *data)
{
	int	i;
	int	j;
	int	count_nsew;

	i = 1;
	count_nsew = 0;
	while (i < data->h_map2d - 1)
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
				|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W')
				count_nsew++;
			else if (data->map2d[i][j] != '0' && data->map2d[i][j] != '1'
				&& data->map2d[i][j] != ' ')
				exit_free(data, -1, "Map error\n");
			j++;
		}
		i++;
	}
	if (count_nsew != 1)
		exit_free(data, -1, "Map error\n");
}

void	is_space_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != ' ')
			return ;
		i++;
	}
	exit_free(data, -1, "Map error\n");
}

void	check_emptyspaceonly(t_data *data)
{
	int	i;

	i = 0;
	while (data->map2d[i])
	{
		if (!data->map2d[i][0])
			exit_free(data, -1, "Map error\n");
		is_space_line(data, data->map2d[i]);
		i++;
	}
}

static int	count_color(char **color)
{
	int	i;

	i = 0;
	while (color[i])
		i++;
	return (i);
}

void	check_colors(t_data *data, int path, int i)
{
	long int	r;
	long int	g;
	long int	b;
	char		**color;
	int			j;

	color = ft_split(data->xpm_path[path], ',');
	if (count_color(color) < 3 || !color)
	{
		free_tab(color);
		exit_free(data, -1, "Map error\n");
	}
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (ft_isdigit(color[i][j]) == 0 && (j != 0 || color[i][j] != '-'))
				return (free_tab(color), exit_free(data, -1, "Map error\n"));
			j++;
		}
		i++;
	}
	r = ft_long_atoi(color[0]);
	g = ft_long_atoi(color[1]);
	b = ft_long_atoi(color[2]);
	free_tab(color);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		exit_free(data, -1, "Map error\n");
}

void	check_map(t_data *data)
{
	if (data->h_map2d < 3 || data->w_map2d < 3)
		exit_free(data, -1, "Map error\n");
	check_mapcomponents(data);
	check_btlines(data);
	check_rlline(data);
	check_emptyspaceonly(data);
	check_colors(data, 4, 0);
	check_colors(data, 5, 0);
}
