/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:17:35 by sel-jama          #+#    #+#             */
/*   Updated: 2023/05/13 17:25:25 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(char *c, t_game **s)
{
	void	*img;
	int		w;
	int		h;
	int		n;

	*c = '0';
	n = 0;
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/way.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
	(*s)->diamonds--;
}

void	move_up(t_game **s)
{
	int		w;
	int		h;
	int		n;
	void	*img;

	n = 0;
	if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] == 'E')
	{
		if (check_and_exit_door(s))
			return ;
	}
	else if ((*s)->map[((*s)->y / 64) - 1][((*s)->x / 64)] != '1')
	{
		put_floor(s);
		(*s)->y -= 64;
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_up.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}

void	move_down(t_game **s)
{
	int		w;
	int		h;
	int		n;
	void	*img;

	n = 0;
	if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] == 'E')
	{
		if (check_and_exit_door(s))
			return ;
	}
	else if ((*s)->map[((*s)->y / 64) + 1][((*s)->x / 64)] != '1')
	{
		put_floor(s);
		(*s)->y += 64;
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_down.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}

void	move_left(t_game **s)
{
	int		w;
	int		h;
	int		n;
	void	*img;

	n = 0;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] == 'E')
	{
		if (check_and_exit_door(s))
			return ;
	}
	else if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) - 1] != '1')
	{
		put_floor(s);
		(*s)->x -= 64;
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_left.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}

void	move_right(t_game **s)
{
	int		w;
	int		h;
	int		n;
	void	*img;

	n = 0;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] == '1')
		return ;
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] == 'E')
	{
		if (check_and_exit_door(s))
			return ;
	}
	else if ((*s)->map[((*s)->y / 64)][((*s)->x / 64) + 1] != '1')
	{
		put_floor(s);
		(*s)->x += 64;
	}
	if ((*s)->map[((*s)->y / 64)][((*s)->x / 64)] == 'C')
		ft_collect(&((*s)->map[((*s)->y / 64)][((*s)->x / 64)]), s);
	img = mlx_xpm_file_to_image((*s)->mlx, "./textures/p_right.xpm", &w, &h);
	if (img)
		n = mlx_put_image_to_window((*s)->mlx, (*s)->wi, img, (*s)->x, (*s)->y);
	if (n == -1)
		ft_error_exit("Failed to draw image to window", 1);
}
