/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:20:18 by migupere          #+#    #+#             */
/*   Updated: 2024/10/24 16:11:05 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void	define_initial_plane(t_game *game)
{
	if (game->player->fov == 'N')
	{
		game->player->dir = create_vector(0, -1);
		game->player->plane = create_vector(0.66, 0);
	}
	else if (game->player->fov == 'S')
	{
		game->player->dir = create_vector(0, 1);
		game->player->plane = create_vector(-0.66, 0);
	}
	else if (game->player->fov == 'W')
	{
		game->player->dir = create_vector(-1, 0);
		game->player->plane = create_vector(0, -0.66);
	}
	else if (game->player->fov == 'E')
	{
		game->player->dir = create_vector(1, 0);
		game->player->plane = create_vector(0, 0.66);
	}
}

void	setup(t_game *game)
{
	game->player->pos = create_vector(game->player->init_pos_x + 0.5,
			game->player->init_pos_y + 0.5);
	define_initial_plane(game);
}