/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:51:03 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/03 23:20:08 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(char** arr, int x, int y, int rows, int cols)
{
    // Check if the current coordinates are out of bounds or the cell is already filled
	if (x < 0 || x > cols - 1 || y < 0 || y > rows - 1 || arr[y][x] == '1' || arr[y][x] == 'S' || arr[y][x] == 'E')
        return ;
    // Fill the current cell with the fill value
	if(arr[y][x] == 'P')
		arr[y][x] = 'P';
	else
    	arr[y][x] = 'S';
    // Recursively fill the adjacent cells
	fill(arr, x-1, y, rows, cols);
	fill(arr, x+1, y, rows, cols);
	fill(arr, x, y-1, rows, cols);
    fill(arr, x, y+1, rows, cols);
}

int	check_filled_map(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' && (map[i+1][j] == 'S' || map[i-1][j] == 'S'
				|| map[i][j+1] == 'S' || map[i][j-1] == 'S'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_remaining_collectibles(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	printf("here %d\n", rows);
	while (i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	check_path(t_game *param)
{
	char	**copy;
	int		i;
	
	copy = (char **)malloc(sizeof(char *) * (param)->rows);
	i = 0; 
	while (i < (param)->rows)
	{
		copy[i] = ft_strdup((param)->map[i]);
		i++;
	}
    printf("Original array:\n"); 
    for (int i = 0; i < (param)->rows; i++){
        printf("%s\n", (param)->map[i]);
    }
	fill(copy, param->x, param->y, param->rows, param->cols);
	printf("New array:\n");
    for (int i = 0; i < (param)->rows; i++)
        printf("%s\n", copy[i]);
	if (check_filled_map(copy) && check_remaining_collectibles(copy, param->rows))
	{
		ft_free_map(copy, param->rows);
		return (1);
	}
	ft_free_map(copy, param->rows);
	return (0);
}
void	set_player_coor(t_game	*param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'P')
			{
				param->x = j;
				param->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}