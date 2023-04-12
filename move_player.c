/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:17:35 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/11 11:28:47 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(so_long **game)
{
	int		width;
	int		height;
    void    *img = NULL;

    if ((*game)->map[((*game)->y_coor / 64) - 1][((*game)->x_coor / 64)] == '1')
        return ;
	if ((*game)->map[((*game)->y_coor / 64) - 1][((*game)->x_coor / 64)] == 'E')
	{
		if ((*game)->diamonds <= 0)
			escape_door(game);
        else
            return ;
	}
	else if ((*game)->map[((*game)->y_coor / 64) - 1][((*game)->x_coor / 64)] != '1')
	{
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
		(*game)->y_coor -= 64;
		// put_text(&game);
	}
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] == 'C')
	{
		(*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] = '0';
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
        (*game)->diamonds--;
    }
	img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/player_up.xpm", &width, &height);
	mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
}

void	move_down(so_long **game)
{
	int		width;
	int		height;
    void    *img = NULL;

    if ((*game)->map[((*game)->y_coor / 64) + 1][((*game)->x_coor / 64)] == '1')
        return ;
	if ((*game)->map[((*game)->y_coor / 64) + 1][((*game)->x_coor / 64)] == 'E')
	{
		if ((*game)->diamonds <= 0)
			escape_door(game);
        else
            return ;
	}
	else if ((*game)->map[((*game)->y_coor / 64) + 1][((*game)->x_coor / 64)] != '1')
	{
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
		(*game)->y_coor += 64;
		// put_text(&game);
	}
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] == 'C')
	{
		(*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] = '0';
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
        (*game)->diamonds--;
    }
	img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/player_down.xpm", &width, &height);
	mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
}

void	move_left(so_long **game)
{
	int		width;
	int		height;
    void    *img = NULL;

    if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) - 1] == '1')
        return ;
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) - 1] == 'E')
	{
		if ((*game)->diamonds <= 0)
			escape_door(game);
        else
            return ;
	}
	else if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) - 1] != '1')
	{
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
		(*game)->x_coor -= 64;
		// put_text(&game);
	}
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] == 'C')
	{
		(*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] = '0';
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
        (*game)->diamonds--;
    }
	img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/player_left.xpm", &width, &height);
	mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
}

void	move_right(so_long **game)
{
	int		width;
	int		height;
    void    *img;
    
    if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) + 1] == '1')
        return ;
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) + 1] == 'E')
	{
		if ((*game)->diamonds <= 0)
			escape_door(game);
        else
            return ;
	}
	else if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64) + 1] != '1')
	{
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
		(*game)->x_coor += 64;
		// put_text(&game);
	}
	if ((*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] == 'C')
	{
		(*game)->map[((*game)->y_coor / 64)][((*game)->x_coor / 64)] = '0';
        img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/way.xpm", &width, &height);
	    mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
        (*game)->diamonds--;
    }
	img = mlx_xpm_file_to_image((*game)->ptr_mlx, "./sprites/player_right.xpm", &width, &height);
	mlx_put_image_to_window((*game)->ptr_mlx, (*game)->window, img, (*game)->x_coor, (*game)->y_coor);
}
