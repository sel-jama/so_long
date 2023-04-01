/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:22:11 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/01 02:22:27 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
    so_long var;
    check_mapfile_name(&av[1]);
    var.map = ft_get_map(av[1]);
    if (!map_is_valid(var.map))
        ft_error_exit("map is invalid");
}   