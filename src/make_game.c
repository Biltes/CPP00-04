/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:30:18 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 22:57:26 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_player_pos(t_game *game)
{
	int	dir;

	dir = 1;
	if (game->player->fov == 'N')
		game->player->dir = (t_coord){0, -dir};
	else if (game->player->fov == 'S')
		game->player->dir = (t_coord){0, dir};
	else if (game->player->fov == 'W')
		game->player->dir = (t_coord){-dir, 0};
	else if (game->player->fov == 'E')
		game->player->dir = (t_coord){dir, 0};
	game->player->movement = (t_coord){0, 0};
	game->player->plane.pos.x = -game->player->dir.y;
	game->player->plane.pos.y = game->player->dir.x;
	game->key = 0;
}

int	make_game(t_game *cub3d)
{
	if (cub3d->key)
		movements(cub3d);
	generate_image(cub3d);
	ft_raycast(cub3d);
	return (EXIT_SUCCESS);
}