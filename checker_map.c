/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chercker_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:08:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/01 01:59:05 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int check_mapfile_name(char **av)
{
    int found;
    found = 0;
    char    *file_name;

    file_name = *av;
    while (file_name)
    {
        if (ft_strncmp(file_name, ".ber", 4) == 0)
        {
            found = 1;
            file_name += 4;
            printf("%s\n", file_name);
            break ;
        }
        file_name++;
    }
    if (found && *file_name == '\0')
        return (0);
    else
        ft_error_exit("invalid file name");
    return (0);
    
}
    
char    **ft_get_map(char *av)
{
    char    *map_line;
    char    *map_lines;
    char    **map;
    int     fd;

    map_lines = ft_strdup("");
    fd = open(av, O_RDONLY);
    if (fd < 0)
        ft_error_exit("failed to open file");
    map_line = get_next_line(fd);
    while (map_line != '\0' && *map_line != '\n')
    {
        map_lines = ft_strjoin(map_lines, map_line);
        free(map_line);
        map_line = get_next_line(fd);
    }
    map = ft_split(map_lines, '\n');
    int i;
    i = -1;
    while (map[++i])
        map[i] = ft_strjoin(map[i], "\n");
    free(map_lines);
    return (map);
}

int is_map_rectangle(char **map, int rows, int cols)
{
    int i;
    i = 0;
    while(i < rows)
    {
        if (ft_strlen(map[i]) - 1 != cols) 
            return (0);
        i++;
    }
    return (1);
}

int is_map_surrounded_by_walls(char **map, int rows, int cols)
{
    // check top and bottom rows
    int j;
    j = 0;
    while(j < cols)
    {
        if (map[0][j] != '1' || map[rows-1][j] != '1')
            return (0);
        j++;
    }
    // check left and right columns
    int i;
    i = 0;
    while(i < rows)
    {
        if (map[i][0] != '1' || map[i][cols-1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int is_map_well_composed(char **map, int rows, int cols)
{
    int i;
    int j;

    i = 0;
    while(i < rows-1)
    {
        j = 0;
        while (j < cols-1)
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

int map_contains_one_exit(char **map)
{
    int i;
    int j;
    int exit;
    int collectible;
    int start;

    exit = 0;
    collectible = 0;
    start = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                exit += 1;
            if (map[i][j] == 'C')
                collectible += 1;
            if (map[i][j] == 'P')
                start +=1;
            j++;
        }
        i++;
    }
    if (exit == 1 && start == 1 && collectible >= 1)
        return (1);
    return (0); 
}

int map_is_valid(char **map)
{
    int rows;
    int cols;
    int i;

    i = 0;
    while (map[i])
        i++;
    //-1 for the '/n' char in the map
    cols = ft_strlen(map[0]) - 1;
    rows = i;
    if (!is_map_rectangle(map, rows, cols))
        return (0);
    if (!is_map_surrounded_by_walls(map, rows, cols))
        return (0);
    if (!is_map_well_composed(map, rows, cols))
        return (0);
    if (!map_contains_one_exit(map))
        return (0);
    return (1);
}