/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:08:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 16:54:00 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_new_lined_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		map[i] = ft_strjoin(map[i], "\n");
	return (map);
}

char	**ft_get_map(char *av)
{
	char	*map_line;
	char	*map_lines;
	char	**map;
	int		fd;

	map_lines = ft_strdup("");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error_exit("failed to open file", 1);
	map_line = get_next_line(fd);
	if (!map_line)
		return (NULL);
	while (map_line != '\0')
	{
		map_lines = ft_strjoin(map_lines, map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	if (map_lines[ft_strlen(map_lines) - 1] == '\n')
		ft_error_exit("Invalid shap of map", 1);
	map = ft_split(map_lines, '\n');
	map = ft_new_lined_map(map);
	free(map_lines);
	close(fd);
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
