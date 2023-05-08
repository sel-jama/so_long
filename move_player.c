/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:17:35 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/08 01:06:40 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(char *c, t_game **s)
{
	void	*img;
	int		w;
	int		h;

	*c = '0';
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
	(*s)->diamonds--;
}

void	move_up(t_game **s)
{
	int		w;
	int		h;
	void	*img;

	if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] == 'E')
	{
		if ((*s)->diamonds <= 0)
			escape_door(s);
		else
			return ;
	}
	else if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] != '1')
	{
		display_score(s);
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
		mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
		(*s)->y -= 64;
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_up.xpm", &w, &h);
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
}

void	move_down(t_game **s)
{
	int		w;
	int		h;
	void	*img;

	if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] == 'E')
	{
		if ((*s)->diamonds <= 0)
			escape_door(s);
		else
			return ;
	}
	else if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] != '1')
	{
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
		mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
		(*s)->y += 64;
		display_score(s);
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_down.xpm", &w, &h);
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
}

void	move_left(t_game **s)
{
	int		w;
	int		h;
	void	*img;

	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] == 'E')
	{
		if ((*s)->diamonds <= 0)
			escape_door(s);
		else
			return ;
	}
	else if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] != '1')
	{
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
		mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
		(*s)->x -= 64;
		display_score(s);
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_left.xpm", &w, &h);
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
}

void	move_right(t_game **s)
{
	int		w;
	int		h;
	void	*img;

	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] == 'E')
	{
		if ((*s)->diamonds <= 0)
			escape_door(s);
		else
			return ;
	}
	else if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] != '1')
	{
		img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
		mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
		(*s)->x += 64;
		display_score(s);
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_right.xpm", &w, &h);
	mlx_put_image_to_window((*s)->mlx, (*s)->window, img, (*s)->x, (*s)->y);
}
