/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:08:08 by migupere          #+#    #+#             */
/*   Updated: 2024/10/10 12:40:51 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_player_input(t_game *game)
{
	double	new_x;
	double	new_y;
	double	lerp_factor;

	new_x = 0;
	new_y = 0;
	lerp_factor = 1;
	compute_new_player_position(game, &new_x, &new_y);
	if (is_valid_move(game, new_x, new_y))
	{
		game->player->pos.x += lerp_factor * (new_x - game->player->pos.x);
		game->player->pos.y += lerp_factor * (new_y - game->player->pos.y);
	}
	if (game->key.left)
	{
		game->player->dir = rotate_vector(game->player->dir, -1.5);
		game->player->plane = rotate_vector(game->player->plane, -1.5);
	}
	if (game->key.right)
	{
		game->player->dir = rotate_vector(game->player->dir, 1.5);
		game->player->plane = rotate_vector(game->player->plane, 1.5);
	}
}

int	get_direction_sign(double value)
{
	if (value < 0)
		return (-1);
	return (1);
}

bool	is_valid_move(t_game *game, double new_x, double new_y)
{
	double	margin;

	margin = 0.1;
	if (game->map->map_matrix[(int)(new_y + margin * get_direction_sign
			(new_y - game->player->pos.y))][(int)new_x] == '1')
		return (false);
	if (game->map->map_matrix[(int)new_y][(int)(new_x + margin
		* get_direction_sign(new_x - game->player->pos.x))] == '1')
		return (false);
	if (game->map->map_matrix[(int)(new_y + margin * get_direction_sign
			(game->player->plane.y))][(int)new_x] == '1')
		return (false);
	if (game->map->map_matrix[(int)new_y][(int)(new_x + margin
		* get_direction_sign(game->player->plane.x))] == '1')
		return (false);
	return (true);
}

void	compute_new_player_position(t_game *game, double *new_x, double *new_y)
{
	double	move_speed;

	move_speed = game->player->move_speed;
	*new_x = game->player->pos.x;
	*new_y = game->player->pos.y;
	if (game->key.w)
	{
		*new_x += game->player->dir.x * move_speed;
		*new_y += game->player->dir.y * move_speed;
	}
	if (game->key.s)
	{
		*new_x -= game->player->dir.x * move_speed;
		*new_y -= game->player->dir.y * move_speed;
	}
	if (game->key.a)
	{
		*new_x -= game->player->plane.x * move_speed;
		*new_y -= game->player->plane.y * move_speed;
	}
	if (game->key.d)
	{
		*new_x += game->player->plane.x * move_speed;
		*new_y += game->player->plane.y * move_speed;
	}
}
