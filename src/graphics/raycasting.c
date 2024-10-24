/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:19:40 by migupere          #+#    #+#             */
/*   Updated: 2024/10/24 19:55:30 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_step_direction(double dir)
{
	if (dir < 0)
		return (-1);
	else
		return (1);
}

void	calculate_delta_distances(t_dda *dda)
{
	// if (dda->ray_dir.x == 0)
	// 	dda->delta_dist.x = HUGE_VAL;
	// else
		dda->delta_dist.x = fabs(1 / dda->ray_dir.x);
	// if (dda->ray_dir.y == 0)
	// 	dda->delta_dist.y = HUGE_VAL;
	// else
		dda->delta_dist.y = fabs(1 / dda->ray_dir.y);
}

void	calculate_side_distances(t_dda *dda, t_player *player)
{
	dda->map_pos.x = (int)player->pos.x;
	dda->map_pos.y = (int)player->pos.y;
	if (dda->ray_dir.x < 0)
	{
		get_step_direction(dir);
		dda->side_dist.x = (player->pos.x - dda->map_pos.x) * dda->delta_dist.x;
	}
	else
		dda->side_dist.x = (dda->map_pos.x + 1.0 - player->pos.x)
			* dda->delta_dist.x;
	if (dda->ray_dir.y < 0)
		dda->side_dist.y = (player->pos.y - dda->map_pos.y)
			* dda->delta_dist.y;
	else
		dda->side_dist.y = (dda->map_pos.y + 1.0 - player->pos.y)
			* dda->delta_dist.y;
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = false;
	
	while(!hit)
	{
		if (game->ray.side_dist.x < game->ray.side_dist.y)
		{
			game->ray.side_dist.x += game->ray.delta_dist.x;
			game->player->init_pos_x += game->ray.step.x;
			game->ray.side = true;
		}
		else
		{
			game->ray.side_dist.y += game->ray.delta_dist.y;
			game->player->init_pos_y += game->ray.step.y;
			game->ray.side = false;
		}
		if (game->map->map_matrix[(int)game->player->init_pos_y][(int)game->player->init_pos_x] == '1')
			hit = true;
	}
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = game->ray.side_dist.x - game->ray.delta_dist.x;
	else
		game->ray.perp_wall_dist = game->ray.side_dist.y - game->ray.delta_dist.y;
}

int	draw_rays(t_game *game)
{
	int		x;
	t_dda	dda;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		dda.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		dda.ray_dir.x = game->player->dir.x + game->player->plane.x
			* dda.camera_x;
		dda.ray_dir.y = game->player->dir.y + game->player->plane.y
			* dda.camera_x;
		dda.step.x = get_step_direction(dda.ray_dir.x);
		dda.step.y = get_step_direction(dda.ray_dir.y);
		calculate_delta_distances(&dda);
		calculate_side_distances(&dda, game->player);
		perform_dda(&game);
		draw_walls_and_background(&dda, game, x);
		x++;
	}
	return (0);
}
