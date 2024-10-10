/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:35:48 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/06 14:19:57 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
	{
		return ;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	free_structs(t_game *game)
{
	if (game->map->no_texture)
		free(game->map->no_texture);
	if (game->map->so_texture)
		free(game->map->so_texture);
	if (game->map->we_texture)
		free(game->map->we_texture);
	if (game->map->ea_texture)
		free(game->map->ea_texture);
	if (game->map->map_matrix)
		free_arr(game->map->map_matrix);
	if (game->map != NULL)
		free(game->map);
	if (game->player != NULL)
		free(game->player);
	return (0);
}

int	error_exit(t_game *game, char *message)
{
	(void) game;
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	//free_game(game);
	exit(errno);
}
