/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chercker_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:08:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/28 01:42:17 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

// void check_mapfile_name(char *av)
// {
//     if(ft_strnstr(av, ".ber", ft_strlen(av)))
//         return(0);
//     else
//         ft_exit_error("Error: invalid file name");
// }

char    **ft_get_map(char *av)
{
    char    *map_line;
    char    *map_lines;
    char    **map;
    int     fd;

    map_line = ft_strdup("");
    fd = open(av, O_RDONLY);
    // if (fd < 0)
    //     ft_exit_error("failed to open file");
    map_line = get_next_line(fd);
    while (map_line != '\0' && *map_line != '\n')
    {
        map_lines = ft_strjoin(map_lines, map_line);
        free(map_line);
        map_line = get_next_line(fd);
    }
    map = ft_split(map_lines, '\n');
    free(map_lines);
    return (map);
}

// void    map_is_valid(char *av)
// {
    
// }