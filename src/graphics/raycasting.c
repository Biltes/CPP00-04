/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:19:40 by migupere          #+#    #+#             */
/*   Updated: 2024/10/10 14:32:33 by migupere         ###   ########.fr       */
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
	if (dda->ray_dir.x == 0)
		dda->delta_dist.x = HUGE_VALF;
	else
		dda->delta_dist.x = fabs(1 / dda->ray_dir.x);
	if (dda->ray_dir.y == 0)
		dda->delta_dist.y = HUGE_VALF;
	else
		dda->delta_dist.y = fabs(1 / dda->ray_dir.y);
}

void	calculate_side_distances(t_dda *dda, t_player *player)
{
	dda->map_pos.x = (double)player->init_pos_x;
	dda->map_pos.y = (double)player->init_pos_y;
	if (dda->ray_dir.x < 0)
		dda->side_dist.x = (player->pos.x - dda->map_pos.x) * dda->delta_dist.x;
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

void	perform_dda(t_dda *dda, t_render *game)
{
	
	while (game->map->map_matrix[(int)dda->map_pos.y][(int)dda->map_pos.x] != '1')
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->map_pos.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->map_pos.y += dda->step.y;
			dda->side = 1;
		}
	}
	if (dda->side == 0)
		dda->perp_wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->perp_wall_dist = dda->side_dist.y - dda->delta_dist.y;
}

int	draw_rays(t_game *game)
{
	int		x;
	t_dda	dda;

	dda.perp_wall_dist = 0;
	dda.hit = 0;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		dda.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		dda.pixel = x_vector(game->player->plane, dda.camera_x);
		dda.ray_dir = add_vector(game->player->dir, dda.pixel);
		dda.step.x = get_step_direction(dda.ray_dir.x);
		dda.step.y = get_step_direction(dda.ray_dir.y);
		calculate_delta_distances(&dda);
		calculate_side_distances(&dda, game->player);
		perform_dda(&dda, &game->render);
		draw_walls_and_background(&dda, game, x);
		x++;
	}
	return (0);
}