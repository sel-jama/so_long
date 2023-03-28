/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:17:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/28 01:40:48 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
    // check_mapfile_name(av[1]);
    // if(!map_is_valid(av))
    //     ft_exit_error("map is invalid");
    char **map;
    map = ft_get_map(av[1]);
    int i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
            
    
}