/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:52:08 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/09 14:25:25 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	are_color_valid(t_game *game)
{
	int	i;
	int	*ceiling_color;
	int	*floor_color;

	i = 0;
	ceiling_color = game->map->ceiling;
	while (ceiling_color[i] && i < 3)
	{
		if (ceiling_color[i] > 255)
		{
			ft_print_err("Error: Ceiling color index is not valid.");
			return (1);
		}
		i++;
	}
	i = 0;
	floor_color = game->map->floor;
	while (floor_color[i] && i < 3)
	{
		if (floor_color[i] > 255)
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
	if(!ft_strncmp(line, "F ", 1))
	{
		temp = ft_split(line + 1, ',');
		while(temp[++i])
			game->map->floor[i] = ft_atoi(temp[i]);
		free_arr(temp);
	}
	i = -1;
	if(!ft_strncmp(line, "C ", 1))
	{
		temp = ft_split(line + 1, ',');
		while(temp[++i])
			game->map->ceiling[i] = ft_atoi(temp[i]);
		free_arr(temp);
	}
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
