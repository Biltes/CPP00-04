/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:19:04 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 16:31:40 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	seed(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i] && i < height)
	{
		j = 1;
		while (map[i][j] && j < width)
		{
			if (map[i][j] == '0' ||
			map[i][j] == getchr("NSWE", map[i][j]))
			{
				if (map[i][j - 1] == '#' || map[i][j + 1] == '#' ||
				map[i + 1][j] == '#' || map[i + 1][j - 1] == '#' ||
				map[i + 1][j + 1] == '#' || map[i - 1][j] == '#' ||
				map[i - 1][j - 1] == '#' || map[i - 1][j + 1] == '#')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	map_height(char **map_line, int *max_width)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (*max_width < (int)ft_strlen(map_line[i]))
			*max_width = (int)ft_strlen(map_line[i]) + 2;
		i++;
	}
	return (i);
}

static char	**create_sqd_map(int height, int max_width, char **map_line)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)ft_calloc(height, sizeof(char *));
	if (!temp)
		return (NULL);
	while (i < height -1)
	{
		temp[i] = (char *)ft_calloc((max_width + 1), sizeof(char));
		if (!temp[i])
			return (NULL);
		ft_memset(temp[i], '#', (max_width) * sizeof (char));
		temp[i][max_width] = '\0';
		i++;
	}
	i = 0;
	while (temp[i + 1])
	{
		if (map_line[i])
			ft_memcpy(temp[i + 1] + 1, map_line[i], ft_strlen(map_line[i]));
		i++;
	}
	return (temp);
}

void	fill_map(t_game *game, char **squared_map, int height)
{
	int	i;
	int	j;

	game->map->map_matrix = (char **)ft_calloc(height, sizeof(char *));
	if (!game->map->map_matrix)
		return ;
	i = 0;
	while (squared_map[i])
	{
		j = 0;
		while (squared_map[i][j])
		{
			if (squared_map[i][j] == ' ')
				squared_map[i][j] = '#';
			j++;
		}
		game->map->map_matrix[i] = ft_strdup(squared_map[i]);
		i++;
	}
}

int	flood_fill(char **map_line, t_game *game)
{
	int		max_width;
	int		height;
	char	**squared_map;

	max_width = 0;
	height = map_height(map_line, &max_width) + 3;
	squared_map = create_sqd_map(height, max_width, map_line);
	fill_map(game, squared_map, height);
	game->map->n_lines = height;
	game->map->width = max_width;
	if (seed(squared_map, height - 2, max_width - 1) != 0)
	{
		ft_print_err("Error: Map or player is not enclosed by walls.");
		free_arr(squared_map);
		return (1);
	}
	free_arr(squared_map);
	return (0);
}
