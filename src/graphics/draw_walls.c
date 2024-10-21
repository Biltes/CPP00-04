/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:00:05 by migupere          #+#    #+#             */
/*   Updated: 2024/10/20 23:35:19 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	intersection_point(t_dda *ray, t_game *game, t_rays *wall)
{
	if (ray->hit == 0)
		wall->intersection.x = game->player->pos.y + ray->perp_wall_dist
			* ray->ray_dir.y;
	else
		wall->intersection.x = game->player->pos.x + ray->perp_wall_dist
			* ray->ray_dir.x;
	wall->intersection.x -= floor(wall->intersection.x);
}

static void	find_texture_position_x(t_dda *ray, t_game *game, t_rays *wall)
{
	game->img_info.tex_x = (int)(wall->intersection.x * game->texture->width);
	if ((ray->hit == 0 && ray->ray_dir.x < 0)
		|| (ray->hit == 1 && ray->ray_dir.y > 0))
		game->img_info.tex_x = game->texture->width - game->img_info.tex_x - 1;
	game->img_info.scale = (double)game->texture->height / game->render->height;
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
	t_game	wall;
	t_render	*texture;

	texture = set_wall_texture(game, ray);
	wall.render->height = (int)(HEIGHT / ray->perp_wall_dist);
	wall.img_info.draw_start = (HEIGHT - wall.render->height) / 2;
	wall.img_info.draw_end = (HEIGHT + wall.render->height) / 2;
	// wall.img_info.draw_start = fmax(0, wall.img_info.draw_start);
	intersection_point(ray, game, &wall);
	find_texture_position_x(ray, game, &wall);
	wall.img_info.pos_texture = (wall.img_info.draw_start - HEIGHT / 2
			+ wall.render->height / 2) * wall.img_info.scale;
	draw_ceiling(game, x, wall.img_info.draw_start);
	draw_wall(game, &wall, texture, x);
	draw_floor(game, x, wall.img_info.draw_end);
}
