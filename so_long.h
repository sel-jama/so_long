/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:34:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/05 05:59:03 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
typedef struct s_so_long
{
    char **map;
}so_long;

int     check_mapfile_name(char **av);
char    **ft_get_map(char *av);
int     map_is_valid(char **map, int rows, int cols);
int     map_contains_one_exit(char **map);
int     is_map_well_composed(char **map, int rows, int cols);
int     is_map_surrounded_by_walls(char **map, int rows, int cols);
int     is_map_rectangle(char **map, int rows, int cols);
void    ft_error_exit(char *msg);
void    ft_broadcast_game(int col, int row);
int     ft_key_hook(int keycode);
int     ft_mouse_hook(int button, int x, int y);

#endif