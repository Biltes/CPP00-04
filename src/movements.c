/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:38:53 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/19 19:50:37 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



int	ft_check_buffer_zone(t_game *game, t_coord new_pos)
{
	double	angle;
	double	check_x;
	double	check_y;
	int		map_x;
	int		map_y;

	angle = 0;
	if (angle < 2 * PI)
	{
		check_x = new_pos.x + cos(angle) * BUFFER_DISTANCE;
		check_y = new_pos.y + sin(angle) * BUFFER_DISTANCE;
		map_x = (int)check_x;
		map_y = (int)check_y;
		if (map_x < 0 || map_y < 0 || map_y >= game->map->n_lines
			|| map_x >= (int)ft_strlen(game->map->map_matrix[map_y]))
			return (0);
		if (game->map->map_matrix[map_y][map_x] != '0')
			return (0);
		angle += PI / 8;
	}
	return (1);
}

int	ft_is_valid_move_with_buffer(t_game *game, t_coord new_pos)
{
	int	new_x;
	int	new_y;

	new_x = (int)new_pos.x;
	new_y = (int)new_pos.y;
	if (new_x < 0 || new_y < 0 || new_y >= game->map->n_lines
		|| new_x >= game->map->width)
		return (0);
	if (game->map->map_matrix[new_y][new_x] != '0')
		return (0);
	if (!ft_check_buffer_zone(game, new_pos))
		return (0);
	return (1);
}

void	ft_rotate(t_game *game)
{
	t_player	*player;
	double		angle;
	double		old_dir_x;
	double		old_plane_x;

	player = game->player;
	old_dir_x = player->dir.x;
	old_plane_x = player->plane.pos.x;
	if (game->key == LEFT || game->key == RIGHT)
	{
		angle = player->angle * (double)(PI / 180)*ROTATION_SPEED;
		player->dir.x = (player->dir.x * cos(angle)
				- player->dir.y * sin(angle));
		player->dir.y = (old_dir_x * sin(angle)
				+ player->dir.y * cos(angle));
		player->plane.pos.x = (player->plane.pos.x * cos(angle)
				- player->plane.pos.y * sin(angle));
		player->plane.pos.y = (old_plane_x * sin(angle)
				+ player->plane.pos.y * cos(angle));
	}
}

void	movements(t_game *game)
{
	t_player	*player;
	t_coord		new_pos;

	player = game->player;
	new_pos.x = 0;
	new_pos.y = 0;
	new_pos.x = player->pos.x + player->dir.x
		* SPEED * player->movement.y;
	new_pos.y = player->pos.y + player->dir.y
		* SPEED * player->movement.y;
	if (ft_is_valid_move_with_buffer(game, new_pos))
		player->pos = new_pos;
	new_pos.x = player->pos.x + player->plane.pos.x
		* SPEED * player->movement.x;
	new_pos.y = player->pos.y + player->plane.pos.y
		* SPEED * player->movement.x;
	if (ft_is_valid_move_with_buffer(game, new_pos))
		player->pos = new_pos;
	ft_rotate(game);
}