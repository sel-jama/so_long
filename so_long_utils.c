/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:04:25 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/11 10:32:01 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void    ft_error_exit(char *msg)
{
    ft_putstr_fd(msg, 2);
    exit(1);
}

void    ft_free_map(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void escape_door(so_long **game)
{
    ft_free_map((*game)->map);
    mlx_destroy_window((*game)->ptr_mlx, (*game)->window);
    exit(0);
}

void    count_collectibles(so_long *game)
{
    int i;
    int j;

    game->diamonds = 0;    
    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == 'C')
                game->diamonds++;
            j++;
        }
        i++;
    }
}