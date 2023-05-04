/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:12:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/27 18:09:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == 13)
		move_up(&game);
	else if (keycode == KEY_DOWN || keycode == 1)
		move_down(&game);
	else if (keycode == KEY_LEFT || keycode == 0)
		move_left(&game);
	else if (keycode == KEY_RIGHT || keycode == 2)
		move_right(&game);
	else if (keycode == 53)
		exit (0);
	return (0);
}

int	ft_free_exit(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(0);
}

void	ft_broadcast_game(t_game *game, int col, int row)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, col * 64, row * 64, "so_long");
	parse_game_board(&game);
	mlx_hook(game->window, 2, 0, ft_key_hook, game);
	mlx_hook(game->window, 17, 0, ft_free_exit, game);
	mlx_loop(game->mlx);
}

void	parse_game_board(t_game **game)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	col;
	int	row;

	i = 0;
	y = 0;
	col = (*game)->cols;
	row = (*game)->rows;
	while (row > 0)
	{
		j = 0;
		x = 0;
		while (col > 0)
		{
			image_parser((*game)->map[i][j], x, y, game);
			x += 64;
			j++;
			col--;
		}
		col = (*game)->cols;
		i++;
		y += 64;
		row--;
	}
}

void	image_parser(char map_case, int x, int y, t_game **s)
{
	void	*img;
	int		w;
	int		h;

	if (map_case == '1')
		img = mlx_xpm_file_to_image((*s)->mlx, "./sprites/wall.xpm", &w, &h);
	else
		img = mlx_xpm_file_to_image((*s)->mlx, "./sprites/way.xpm", &w, &h);
	if (!img)
		return ;
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, x, y);
	if (map_case == 'P')
	{
		(*s)->x = x;
		(*s)->y = y;
		img = mlx_xpm_file_to_image((*s)->mlx, "./sprites/p_down.xpm", &w, &h);
	}
	if (map_case == 'C')
		img = mlx_xpm_file_to_image((*s)->mlx, "./sprites/diamond.xpm", &w, &h);
	if (map_case == 'E')
	{
		(*s)->x_e = x;
		(*s)->y_e = y;
		img = mlx_xpm_file_to_image((*s)->mlx, "./sprites/door.xpm", &w, &h);
	}
	if (!img)
		return ;
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, x, y);
}
