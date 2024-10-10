/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:42:26 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/08 14:04:10 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_map_matrix(char **map_line, t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	coords[2];
	int	garbage;
	
	coords[0] = 0;
	coords[1] = 0;
	player_count = 0;
	i = 0;
	garbage = 0;
	if (flood_fill(map_line + 6, game) != 0)
	{
		ft_print_err("Error: Map is not enclosed by walls.");
		return (1);
	}
	while (game->map->map_matrix[i])
	{
		j = 0;
		while (game->map->map_matrix[i][j])
		{
			if (game->map->map_matrix[i][j] == 'N' || game->map->map_matrix[i][j] == 'S' || game->map->map_matrix[i][j] == 'E' || game->map->map_matrix[i][j] == 'W')
			{
				coords[0] = i;
				coords[1] = j;
				game->player->fov = game->map->map_matrix[i][j];
				player_count++;
			}
			else if (game->map->map_matrix[i][j] != '0' && game->map->map_matrix[i][j] != '1' && game->map->map_matrix[i][j] != '#')
				garbage++;
			j++;
		}
		i++;
	}
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
	game->player->init_pos_y = coords[0];
	game->player->init_pos_x = coords[1];
	
	return (0);
}
