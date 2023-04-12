/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:12:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/12 05:13:48 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int ft_key_hook(int keycode, so_long *game)
{
    // printf("%d",keycode);
    if (keycode == KEY_UP || keycode == 'W')
        move_up(&game);
    else if (keycode == KEY_DOWN || keycode == 'A')
        move_down(&game);
    else if (keycode == KEY_LEFT || keycode == 'S')
        move_left(&game);
    else if (keycode == KEY_RIGHT || keycode == 'D')
        move_right(&game);
    else if (keycode == 53)
        //free and destroy
        exit (0);
    return (0);
}

int ft_free_exit(int keycode)
{
    printf("%d\n",keycode);
    exit(0);
}

void    ft_broadcast_game(so_long *game, int col, int row)
{
    game->ptr_mlx = mlx_init();
    game->window = mlx_new_window(game->ptr_mlx, col * 64, row * 64, "so_long");
    parse_game_board(&game);
    mlx_hook(game->window, 2, 0, ft_key_hook, game);
    mlx_hook(game->window, 17, 0, ft_free_exit, game);
    mlx_loop(game->ptr_mlx);
 }

void    parse_game_board(so_long **game)
{
    int i;
    int j;
    int x;
    int y;
    int col;
    // int row;

    i = 0;
    y = 0;
    col = (*game)->cols;
    // row = (*game)->rows;
    while((*game)->rows > 0)
    {
        j = 0;
        x = 0;
        while(col > 0)
        {
            image_parser((*game)->map[i][j], x, y, game);
            x += 64;
            j++;
            col--;    
        }
        col = (*game)->cols;
        i++;
        y += 64;
        ((*game)->rows)--;
    }
}

void image_parser(char map_case, int x, int y, so_long **game)
{
    void    *img;
    int     w;
    int     h;

    if (map_case == '1')
    {
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/wall.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
    }
    else if (map_case == '0')
    {
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
    }
    else if (map_case == 'P')
    {
        (*game)->x_coor = x;
        (*game)->y_coor = y;
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/player_down.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
    }
    else if (map_case == 'C')
    {
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/diamond.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
    }
    else if (map_case == 'E')
    {
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/exit_door.xpm", &w, &h);
        mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, x, y);
    }
    else
        return ;
}