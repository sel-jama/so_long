/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 01:04:25 by sel-jama          #+#    #+#             */
/*   Updated: 2023/04/12 13:53:28 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	escape_door(t_game **game)
{
	ft_free_map((*game)->map);
	mlx_destroy_window((*game)->mlx, (*game)->window);
	exit(0);
}

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	game->diamonds = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->diamonds++;
			j++;
		}
		i++;
	}
	if (game->diamonds < 1)
		ft_error_exit("invalid map");
}

void	display_score(t_game **game)
{
	char	*s;

	s = ft_itoa((*game)->score);
	(*game)->score++;
	ft_putnbr_fd((*game)->score, 1);
	ft_putchar_fd('\n', 0);
	mlx_string_put((*game)->mlx, (*game)->window, 20, 10, 0xffffff, s);
	free(s);
}
