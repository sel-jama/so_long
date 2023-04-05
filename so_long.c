/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:36:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/05 05:46:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    so_long var;
    int     cols;
    int     rows;

    if (ac != 2)
        ft_error_exit("invalid number of arguments");
    check_mapfile_name(&av[1]);
    var.map = ft_get_map(av[1]);
    rows = 0;
    while (var.map[rows])
        rows++;
    //-1 for the '/n' char in the map
    cols = ft_strlen(var.map[0]) - 1;
    if (!map_is_valid(var.map, rows, cols))
        ft_error_exit("invalid map");
    ft_broadcast_game(cols, rows);
    return (0);
}