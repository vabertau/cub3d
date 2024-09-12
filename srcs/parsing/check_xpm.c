/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:05:01 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 14:05:43 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* checks if file exists */
void	is_existing(t_data *data, char *xpm_path)
{
	int	fd;

	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		exit_free(data, -1, "Instruction error\n");
	close(fd);
}

/* Checks if file is of type filename.xpm with xpm extension
and that file exists*/
void	check_xpm(t_data *data, char *xpm_path)
{
	int	i;

	i = 0;
	if (ft_strlen(xpm_path) < 5)
		exit_free(data, -1, "xpm error\n");
	if (ft_strncmp(".xpm", &(xpm_path[ft_strlen(xpm_path) - 4]), 4))
		exit_free(data, -1, "xpm error\n");
	is_existing(data, xpm_path);
}

/* checks instructions that have been parsed:
if it finds a 0, return because all instructions have not been parsed

when all instructions have been parsed we will check if count_instr	is = 4
for all instr

otherwise exit_free */
int	check_countinstr(t_data *data, int *count_instr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (count_instr[i] == 0)
			return (0);
		if (count_instr[i] != 1)
			exit_free(data, -1, "Parsing error\n");
		i++;
	}
	return (1);
}
