/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:34:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/01 02:11:17 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>

typedef struct s_so_long
{
    char **map;
}so_long;

int     check_mapfile_name(char **av);
char    **ft_get_map(char *av);
int     map_is_valid(char **map);
int     map_contains_one_exit(char **map);
int     is_map_well_composed(char **map, int rows, int cols);
int     is_map_surrounded_by_walls(char **map, int rows, int cols);
int     is_map_rectangle(char **map, int rows, int cols)
void    ft_error_exit(char *msg);

#endif