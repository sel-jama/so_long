/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 03:12:10 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 17:26:52 by sel-jama         ###   ########.fr       */
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
	game->wi = mlx_new_window(game->mlx, col * 64, row * 64, "so_long");
	if (game->wi == NULL)
		ft_error_exit("Failed to creat a new window", 1);
	parse_game_board(&game, game->rows, game->cols);
	mlx_hook(game->wi, 2, 0, ft_key_hook, game);
	mlx_hook(game->wi, 17, 0, ft_free_exit, game);
	mlx_loop(game->mlx);
}

void	parse_game_board(t_game **game, int row, int col)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
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
	int		w;
	int		h;
	int		n;
	void	*img;

	n = 0;
	if (map_case == '1')
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/wall.xpm", &w, &h);
	else
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, x, y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
	if (map_case == 'P')
		img = put_player(s, x, y);
	if (map_case == 'C')
		img = mlx_xpm_file_to_image((*s)->mlx,
				"./textures/diamond.xpm", &w, &h);
	if (map_case == 'E')
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/door.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, x, y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}
