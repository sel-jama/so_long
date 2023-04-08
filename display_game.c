/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:12:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/08 10:28:23 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int ft_key_hook(int keycode, void *param)
{
    if(keycode == 53)
        exit(0);
    return (0);
}

int ft_free_exit(int keycode, void *param)
{
    ft_free_map(param->map);
}

void    ft_broadcast_game(so_long *game, int col, int row)
{
    void    *ptr_mlx;
    void    *window;

    ptr_mlx = mlx_init();
    window = mlx_new_window(ptr_mlx, col * 64, row * 64, "so_long");
    parse_game_image(&game);
    mlx_hook(window, 2, 0, ft_key_hook, game);
    mlx_hook(window, 17, 0, ft_free_exit, game);
    mlx_loop(ptr_mlx);
 }

void    parse_game_board(so_long *game)
{
    int i;
    int j;
    int x;
    int y;
    int col;
    int

    i = 0;
    y = 0;
    col = game->cols;
    while(game->rows > 0)
    {
        j = 0;
        x = 0;
        while(col > 0)
        {
            image_parser(game->map[i][j], x, y, &game);
            x += 64;
            j++;
            col--;    
        }
        i++;
        y += 64;
        game->rows--;
    }
}