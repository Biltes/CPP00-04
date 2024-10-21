/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:42:26 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 23:03:45 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_numbers(int player_count, int garbage)
{
	if (player_count != 1)
	{
		ft_print_err("Error: Wrong number of players on map.");
		return (1);
	}
	if (garbage != 0)
	{
		ft_print_err("Error: Garbage characters on map.");
		return (1);
	}
	return (0);
}

static int	get_dir_and_fov(t_game *game, int player_count, int garbage)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game->map->map_matrix[i])
	{
		j = 0;
		while (game->map->map_matrix[i][j])
		{
			c = game->map->map_matrix[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				
				game->player->pos.y = i;
				game->player->pos.x = j;
				game->player->fov = c;
				player_count++;
			}
			else if (c != '0' && c != '1' && c != '#')
				garbage++;
			j++;
		}
		i++;
	}
	return (check_numbers(player_count, garbage));
}

int	parse_map_matrix(char **map_line, t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	garbage;

	player_count = 0;
	i = 0;
	garbage = 0;
	if (flood_fill(map_line + 6, game) != 0)
		return (1);
	return (get_dir_and_fov(game, player_count, garbage));
}
