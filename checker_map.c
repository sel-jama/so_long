/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:08:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/08 06:11:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapfile_name(char **av)
{
	int		found;
	char	*file_name;

	found = 0;
	file_name = *av;
	while (ft_strlen(file_name) >= 4)
	{
		if (ft_strncmp(file_name, ".ber", 4) == 0)
		{
			found = 1;
			file_name += 4;
			break ;
		}
		file_name++;
	}
	if (found && *file_name == '\0')
		return (0);
	else
		ft_error_exit("invalid file name", 1);
	return (0);
}

char	**ft_get_map(char *av)
{
	char	*map_line;
	char	*map_lines;
	char	**map;
	int		fd;
	int		i;

	map_lines = ft_strdup("");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error_exit("failed to open file", 1);
	map_line = get_next_line(fd);
	if (!map_line)
		return (NULL);
	while (map_line != '\0' && *map_line != '\n')
	{
		map_lines = ft_strjoin(map_lines, map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	map = ft_split(map_lines, '\n');
	i = -1;
	while (map[++i])
		map[i] = ft_strjoin(map[i], "\n");
	free(map_lines);
	return (map);
}

int	is_map_rectangle(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (ft_strlen(map[i]) - 1 != (size_t)cols)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_surrounded_by_walls(char **map, int rows, int cols)
{
	int	j;
	int	i;

	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_well_composed(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows - 1)
	{
		j = 0;
		while (j < cols - 1)
		{
			if (map[i][j] != '0' && map[i][j] != '1'
					&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
