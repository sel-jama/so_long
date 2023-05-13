/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:02:27 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 16:51:26 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	escape_door(t_game **game)
{
	ft_free_map((*game)->map, (*game)->rows);
	mlx_destroy_window((*game)->mlx, (*game)->wi);
	exit(0);
}

int	check_and_exit_door(t_game **s)
{
	if ((*s)->diamonds <= 0)
		escape_door(s);
	return (1);
}

void	put_floor(t_game **s)
{
	void	*img;
	int		w;
	int		h;
	int		n;

	n = 0;
	display_score(s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx,
				(*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}

void	*put_player(t_game **s, int x, int y)
{
	void	*img;
	int		w;
	int		h;

	(*s)->x = x;
	(*s)->y = y;
	img = mlx_xpm_file_to_image((*s)->mlx,
			"./textures/p_down.xpm", &w, &h);
	return (img);
}
