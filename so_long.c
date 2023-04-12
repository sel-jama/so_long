/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:36:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/11 09:57:41 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    so_long game_param;

    if (ac != 2)
        ft_error_exit("invalid number of arguments");
    check_mapfile_name(&av[1]);
    game_param.map = ft_get_map(av[1]);
    game_param.rows = 0;
    while (game_param.map[game_param.rows])  
        game_param.rows++;
    //-1 for the '/n' char in the map
    game_param.cols = ft_strlen(game_param.map[0]) - 1;
    if (!map_is_valid(game_param.map, game_param.rows, game_param.cols))
        ft_error_exit("invalid map");
    count_collectibles(&game_param);
    ft_broadcast_game(&game_param, game_param.cols, game_param.rows);
    return (0);
}