/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:12:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/05 06:02:13 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_key_hook(int keycode)
{
    printf("%d\n", keycode);
    if(keycode == 53)
        exit(0);
    return (0);
}

// int ft_mouse_hook(int button, int x, int y)
// {
//     printf("%d %d %d\n", button, x, y);
//     return (0);
// }

void    ft_broadcast_game(int col, int row)
{
    void    *ptr_mlx;
    void    *window;

    ptr_mlx = mlx_init();
    window = mlx_new_window(ptr_mlx, col * 64, row * 64, "so_long");
    mlx_hook(window, 2, 0, ft_key_hook, NULL);
    mlx_loop(ptr_mlx);
}