/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:34:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/11 09:57:25 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123

typedef struct s_so_long
{
    char    **map;
    void    *ptr_mlx;
    void    *window;
    int     cols;
    int     rows;
    int     diamonds;
    int     x_coor;
    int     y_coor;
}so_long;

int     check_mapfile_name(char **av);
char    **ft_get_map(char *av);
int     map_is_valid(char **map, int rows, int cols);
int     map_contains_one_exit(char **map);
int     is_map_well_composed(char **map, int rows, int cols);
int     is_map_surrounded_by_walls(char **map, int rows, int cols);
int     is_map_rectangle(char **map, int rows, int cols);
void    ft_error_exit(char *msg);
void    ft_broadcast_game(so_long *game, int col, int row);
void    parse_game_board(so_long **game);
void    image_parser(char map_case, int x, int y, so_long **game);
int     ft_key_hook(int keycode, so_long *game);
void	move_up(so_long **game);
void	move_down(so_long **game);
void	move_left(so_long **game);
void	move_right(so_long **game);
void    escape_door(so_long **game);
void    count_collectibles(so_long *game);
int     ft_free_exit(int keycode);

#endif