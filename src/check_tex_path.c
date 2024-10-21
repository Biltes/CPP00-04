/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:24:49 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 21:58:37 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_textures(t_game *game, char *temp, char *direction)
{
	if (!ft_strncmp(direction, "NO", 2))
	{
		game->map->no_texture = ft_strdup(temp);
		free(temp);
		return ;
	}
	else if (!ft_strncmp(direction, "SO", 2))
	{
		game->map->so_texture = ft_strdup(temp);
		free(temp);
		return ;
	}
	else if (!ft_strncmp(direction, "WE", 2))
	{
		game->map->we_texture = ft_strdup(temp);
		free(temp);
		return ;
	}
	else if (!ft_strncmp(direction, "EA", 2))
	{
		game->map->ea_texture = ft_strdup(temp);
		free(temp);
		return ;
	}
	return ;
}

static int	check_open(t_game *game, char *path_to_tex, char *direction)
{
	char		*temp;
	int			size;
	int			fd;

	temp = ft_strtrim(path_to_tex + 2, " ");
	size = ft_strlen(temp);
	if (strncmp(temp + size - 4, ".xpm", 4))
	{
		free(temp);
		ft_print_err("Error: Format is not valid.");
		return (1);
	}
	fd = open(temp, O_RDONLY);
	if (fd == -1)
	{
		free(temp);
		perror("Error: cannot open textures. Check paths.");
		return (1);
	}
		set_textures(game, temp, direction);
	return (0);
}

static int	free_all(char *temp, char **directions)
{
	free(temp);
	free_arr(directions);
	return (1);
}

int	check_tex_path(t_game *game, char **path)
{
	int		i;
	int		j;
	char	**directions;
	char	*temp;

	directions = ft_split(DIRECTIONS, ',');
	i = 0;
	while (path[i])
	{
		j = 0;
		while (directions[j] && j < 4)
		{
			temp = ft_strtrim(path[i], " ");
			if (!ft_strncmp(temp, directions[j], 2))
			{
				if (check_open(game, temp, directions[j]) != 0)
					return (free_all(temp, directions));
			}
			free(temp);
			j++;
		}
		i++;
	}
	free_arr(directions);
	return (0);
}
