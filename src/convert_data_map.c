/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:52:08 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 20:18:30 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb_to_hex(int *rgb)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8
			| rgb[2]);
	
	return (color);
}


static int	are_color_valid(t_game *game)
{
	int	i;
	int	*color;

	i = 0;
	color = game->map->ceiling;
	while (color[i] && i < 3)
	{
		if (color[i] > 255)
		{
			ft_print_err("Error: Ceiling color index is not valid.");
			return (1);
		}
		i++;
	}
	i = 0;
	color = game->map->floor;
	while (color[i] && i < 3)
	{
		if (color[i] > 255)
		{
			ft_print_err("Error: Floor color index is not valid.");
			return (1);
		}
		i++;
	}
	return (0);
}

static void	read_fc_color(t_game *game, char *line)
{
	char	**temp;
	int		i;

	i = -1;
	if (!ft_strncmp(line, "F ", 1))
	{
		temp = ft_split(line + 1, ',');
		while (temp[++i])
			game->map->floor[i] = ft_atoi(temp[i]);
		free_arr(temp);
	}
	game->map->f_color = rgb_to_hex(game->map->floor);
	i = -1;
	if (!ft_strncmp(line, "C ", 1))
	{
		temp = ft_split(line + 1, ',');
		while (temp[++i])
			game->map->ceiling[i] = ft_atoi(temp[i]);
		free_arr(temp);
	}
	game->map->c_color = rgb_to_hex(game->map->ceiling);
}

int	convert_data_map(t_game *game, char *temp_raw_map)
{
	char		**map_arr;
	char		**map_matrix;
	int			i;

	i = 0;
	map_arr = ft_split(temp_raw_map, '\n');
	if (check_tex_path(game, map_arr) != 0)
	{
		free_arr(map_arr);
		return (1);
	}
	while (map_arr[i])
		read_fc_color(game, map_arr[i++]);
	free_arr(map_arr);
	map_matrix = ft_split(temp_raw_map, '\n');
	if (are_color_valid(game) != 0 || parse_map_matrix(map_matrix, game) != 0)
	{
		free_arr(map_matrix);
		return (1);
	}
	free_arr(map_matrix);
	return (0);
}
