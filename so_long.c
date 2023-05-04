/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:36:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/04 04:41:47 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_param(t_game *game)
{
	game->cols = 0;
	game->rows = 0;
	game->diamonds = 0;
	game->x = 0;
	game->y = 0;
	game->score = 0;
}

int	main(int ac, char **av)
{
	t_game	game_param;

	if (ac != 2)
		ft_error_exit("invalid number of arguments", 1);
	check_mapfile_name(&av[1]);
	game_param.map = ft_get_map(av[1]);
	ft_init_param(&game_param);
	while (game_param.map[game_param.rows])
		game_param.rows++;
	game_param.cols = ft_strlen(game_param.map[0]) - 1;
	if (!map_is_valid(game_param.map, game_param.rows, game_param.cols))
		ft_error_exit("invalid map", 1);
	count_collectibles(&game_param);
	set_player_coor(&game_param);
	if (!check_path(&game_param))
		ft_error_exit("No available path in the map", 0);
	ft_broadcast_game(&game_param, game_param.cols, game_param.rows);
	ft_free_map(game_param.map, game_param.rows);
	mlx_destroy_window(game_param.mlx, game_param.window);
	return (0);
}
