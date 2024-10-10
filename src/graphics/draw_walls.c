/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:00:05 by migupere          #+#    #+#             */
/*   Updated: 2024/10/10 11:54:47 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	intersection_point(t_dda *ray, t_game *game, t_render *wall)
{
	if (ray->side == 0)
		wall->point_x = game->player->pos.y + ray->perp_wall_dist
			* ray->ray_dir.y;
	else
		wall->point_x = game->player->pos.x + ray->perp_wall_dist
			* ray->ray_dir.x;
	wall->point_x -= floor(wall->point_x);
}

static void	find_texture_position_x(t_dda *ray, t_game *game, t_render *wall)
{
	wall->texture_x = (int)(wall->point_x * game->texture->width);
	if ((ray->side == 0 && ray->ray_dir.x < 0)
		|| (ray->side == 1 && ray->ray_dir.y > 0))
		wall->texture_x = game->texture->width - wall->texture_x - 1;
	wall->texture_step = (double)game->texture->height / wall->height;
}

void	*set_wall_texture(t_game *game, t_dda *ray)
{
	if (ray->hit == 1)
	{
		if (ray->step.y < 0)
			return (game->map->no_texture);
		else
			return (game->map->so_texture);
	}
	else
	{
		if (ray->step.x < 0)
			return (game->map->we_texture);
		else
			return (game->map->ea_texture);
	}
}

void	draw_walls_and_background(t_dda *ray, t_game *game, int x)
{
	t_render	wall;
	t_render	*texture;

	wall.height = 0;
    wall.point_x = 0;
	texture = set_wall_texture(game, ray);
	wall.height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	wall.start_y = (SCREEN_HEIGHT - wall.height) / 2;
	wall.end_y = (SCREEN_HEIGHT + wall.height) / 2;
	wall.start_y = fmax(0, wall.start_y);
	intersection_point(ray, game, &wall);
	find_texture_position_x(ray, game, &wall);
	wall.texture_pos = (wall.start_y - SCREEN_HEIGHT / 2
			+ wall.height / 2) * wall.texture_step;
	draw_ceiling(game, x, wall.start_y);
	draw_wall(game, &wall, texture, x);
	draw_floor(game, x, wall.end_y);
}
