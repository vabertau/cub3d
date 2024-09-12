/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:18:29 by vabertau          #+#    #+#             */
/*   Updated: 2024/07/23 18:57:28 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
ft_strncmp modified so that if one of the char
	* finishes and the other is not finished
-1 is returned
*/
static int	ft_strncmp_cub(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n && us1[i] && us2[i] && us1[i] - us2[i] == 0)
		i++;
	if ((i > 0) && ((!us1[i] && us2[i]) || (us1[i] && !us2[i])))
		return (-1);
	return (us1[i] - us2[i]);
}

/*
Checks for .cub extension
CHECK MAP VALIDITY TO DO
*/
static void	check_ext(t_data *data, char *map)
{
	char	*extension;

	extension = ft_strrchr(map, '.');
	if (!extension || ft_strncmp_cub(extension, ".cub", 5) != 0)
		exit_free(data, -1, "Map format: map.cub\n");
}

void	get_map_size(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_free(data, -1, "Map error\n");
	line = get_next_line(fd);
	if (!line)
		return (close(fd), exit_free(data, -1, "Map error\n"));
	data->map_height = 0;
	while (line)
	{
		data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

/*
Fills data->map_height
Mallocs the corresponding number of lines
To fill data->map with the map
*/
void	get_map(t_data *data, char *file_path)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	get_map_size(data, file_path);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		exit_free(data, -1, "Malloc error\n");
	map = data->map;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_free(data, -1, "fd error\n");
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
}

void	parser(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		exit_free(data, -1, "Usage: cub3D map\n");
	check_ext(data, argv[1]);
	get_map(data, argv[1]);
	get_wall_xpm(data);
	get_map2d(data);
	check_map(data);
	set_player(data);
	init_ray(data);
}
