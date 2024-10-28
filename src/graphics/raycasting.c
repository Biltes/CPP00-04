/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:19:40 by migupere          #+#    #+#             */
/*   Updated: 2024/10/28 17:23:12 by migupere         ###   ########.fr       */
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

void	calculate_side_distances(t_dda *dda, t_game *game)
{
	if (dda->ray_dir.x < 0)
	{
		dda->side_dist.x = (game->player->pos.x - game->player->init_pos_x) * dda->delta_dist.x;
	}
	else
	{
		dda->side_dist.x = (game->player->init_pos_x + 1.0 - game->player->pos.x)
			* dda->delta_dist.x;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->side_dist.y = (game->player->pos.y - game->player->init_pos_y)
			* dda->delta_dist.y;
	}
	else
	{
		dda->side_dist.y = (game->player->init_pos_y + 1.0 - game->player->pos.y)
			* dda->delta_dist.y;
	}
	if (dda->side == 0)
		dda->perp_wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->perp_wall_dist = dda->side_dist.y - dda->delta_dist.y;
	if (game->ray.perp_wall_dist < 0.0001)
		game->ray.perp_wall_dist = 0.5;
}

void	perform_dda(t_game *game)
{
	// int	hit;
	t_dda	*dda;

	// hit = false;
	
	while((game->map->map_matrix[(int)game->player->init_pos_y][(int)game->player->init_pos_x] != '1'))
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			game->player->init_pos_x += dda->step.x;
			dda->side = true;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			game->player->init_pos_y += dda->step.y;
			dda->side = false;
		}
		// if (game->map->map_matrix[(int)game->player->init_pos_y][(int)game->player->init_pos_x] == '1')
		// 	hit = true;
	}
	// if (dda->side == 0)
	// 	dda->perp_wall_dist = dda->side_dist.x - dda->delta_dist.x;
	// else
	// 	dda->perp_wall_dist = dda->side_dist.y - dda->delta_dist.y;
}

int	draw_rays(t_game *game)
{
	int		x;
	t_dda	*dda;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		dda->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		dda->ray_dir.x = game->player->dir.x + game->player->plane.x
			* dda->camera_x;
		dda->ray_dir.y = game->player->dir.y + game->player->plane.y
			* dda->camera_x;
		game->player->init_pos_x = (int)game->player->pos.x;
		game->player->init_pos_y = (int)game->player->pos.y;
		dda->step.x = get_step_direction(dda->ray_dir.x);
		dda->step.y = get_step_direction(dda->ray_dir.y);
		calculate_delta_distances(dda);
		calculate_side_distances(dda, game);
		perform_dda(game);
		draw_walls_and_background(dda, game, x);
		x++;
	}
	return (0);
}
