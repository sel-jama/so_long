/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:34:43 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 16:47:04 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*wi;
	int		cols;
	int		rows;
	int		diamonds;
	int		x;
	int		y;
	int		score;
}t_game;

int		check_mapfile_name(char **av);
char	**ft_get_map(char *av);
int		map_is_valid(char **map, int rows, int cols);
int		map_contains_one_exit_player(char **map);
int		is_map_well_composed(char **map, int rows, int cols);
int		is_map_surrounded_by_walls(char **map, int rows, int cols);
int		is_map_rectangle(char **map, int rows, int cols);
void	ft_error_exit(char *msg, int n);
void	ft_broadcast_game(t_game *game, int col, int row);
void	parse_game_board(t_game **game, int row, int col);
void	image_parser(char map_case, int x, int y, t_game **game);
int		ft_key_hook(int keycode, t_game *game);
void	move_up(t_game **game);
void	move_down(t_game **game);
void	move_left(t_game **game);
void	move_right(t_game **game);
void	escape_door(t_game **game);
void	count_collectibles(t_game *game);
void	ft_init_param(t_game *game);
void	display_score(t_game **game);
void	ft_free_map(char **arr, int rows);
void	ft_collect(char *c, t_game **game);
int		ft_free_exit(int keycode, t_game *game);
int		check_path(t_game *param);
int		check_filled_map(char **map, int rows);
void	fill(char **arr, int x, int y, int rows);
int		check_remaining_collectibles(char **map, int rows);
void	set_player_coor(t_game	*param);
int		check_and_exit_door(t_game **s);
char	**ft_new_lined_map(char **map);
void	put_floor(t_game **s);
void	*put_player(t_game **s, int x, int y);

#endif
