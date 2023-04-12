/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:36:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/12 13:53:50 by sel-jama         ###   ########.fr       */
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
		ft_error_exit("invalid number of arguments");
	check_mapfile_name(&av[1]);
	game_param.map = ft_get_map(av[1]);
	ft_init_param(&game_param);
	while (game_param.map[game_param.rows])
		game_param.rows++;
	game_param.cols = ft_strlen(game_param.map[0]) - 1;
	if (!map_is_valid(game_param.map, game_param.rows, game_param.cols))
		ft_error_exit("invalid map");
	count_collectibles(&game_param);
	ft_broadcast_game(&game_param, game_param.cols, game_param.rows);
	return (0);
}
