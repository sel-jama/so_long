/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:53:05 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 16:46:54 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapfile_name(char **av)
{
	int		found;
	char	*file_name;

	found = 0;
	file_name = ft_strrchr(*av, '.');
	if (ft_strncmp(file_name, ".ber", 4) == 0)
		found = 1;
	if (found)
		return (0);
	else
		ft_error_exit("invalid file name", 1);
	return (0);
}

int	map_contains_one_exit_player(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit += 1;
			if (map[i][j] == 'P')
				player += 1;
			j++;
		}
		i++;
	}
	if (exit == 1 && player == 1)
		return (1);
	return (0);
}

int	map_is_valid(char **map, int rows, int cols)
{
	if (!is_map_rectangle(map, rows, cols))
		return (0);
	if (!is_map_surrounded_by_walls(map, rows, cols))
		return (0);
	if (!is_map_well_composed(map, rows, cols))
		return (0);
	if (!map_contains_one_exit_player(map))
		return (0);
	return (1);
}
