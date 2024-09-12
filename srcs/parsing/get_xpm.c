/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:52:10 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 14:05:38 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_var(int *count_cardinals, int *to_init)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		count_cardinals[i] = 0;
		i++;
	}
	*to_init = 0;
}

// if (!data->xpm_path[instr_index])
// check necessary to avoid double alloc with strtrim when 2 same instr
void	xpm_path_assigncheck(t_data *data, int i, int instr_index,
		int *count_instr)
{
	if (!data->xpm_path[instr_index])
	{
		data->xpm_path[instr_index] = &data->map[i][2];
		data->xpm_path[instr_index] = ft_strtrim(data->xpm_path[instr_index],
				" ");
	}
	check_xpm(data, data->xpm_path[instr_index]);
	count_instr[instr_index]++;
}

void	color_assigncheck(t_data *data, int i, int instr_index,
		int *count_instr)
{
	if (!data->xpm_path[instr_index])
	{
		data->xpm_path[instr_index] = &data->map[i][1];
		data->xpm_path[instr_index] = ft_strtrim(data->xpm_path[instr_index],
				" ");
	}
	count_instr[instr_index]++;
}

void	gwx_inception(t_data *data, int i, int *count_instr)
{
	if (!data->map[i][0])
		i++;
	else if (!ft_strncmp(data->map[i], "NO", 2))
		xpm_path_assigncheck(data, i, 0, count_instr);
	else if (!ft_strncmp(data->map[i], "SO", 2))
		xpm_path_assigncheck(data, i, 1, count_instr);
	else if (!ft_strncmp(data->map[i], "WE", 2))
		xpm_path_assigncheck(data, i, 2, count_instr);
	else if (!ft_strncmp(data->map[i], "EA", 2))
		xpm_path_assigncheck(data, i, 3, count_instr);
	else if (!ft_strncmp(data->map[i], "F", 1))
		color_assigncheck(data, i, 4, count_instr);
	else if (!ft_strncmp(data->map[i], "C", 1))
		color_assigncheck(data, i, 5, count_instr);
	else
		exit_free(data, -1, "Parsing error\n");
}

// Reads first lines of the map to get the paths to the
// corresponding xpm files and to get rgb colors.

// Checks for each line if it starts with the cardinal, if yes
// fills the corresponding path in data->xpm_path.

// checks for double keys, missing keys etc. Checks if
// files exist.
void	get_wall_xpm(t_data *data)
{
	int	i;
	int	count_instr[6];

	init_var((int *)count_instr, &i);
	while (data->map[i])
	{
		if (!data->map[i])
			exit_free(data, -1, "Map error\n");
		gwx_inception(data, i, count_instr);
		if (check_countinstr(data, (int *)(count_instr)))
			break ;
		i++;
	}
}
