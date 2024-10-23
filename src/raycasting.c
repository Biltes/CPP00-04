/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:26:36 by jmarinho          #+#    #+#             */
/*   Updated: 2024/10/19 18:18:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_ray_intersections(t_game *game)
{
	if (game->ray.direction.x < 0)
	{
		game->ray.map_mov.x = -1;
		game->ray.intersection.x = (game->player->pos.x
				- game->player->int_pos_x) * game->ray.delta.x;
	}
	else
	{
		game->ray.map_mov.x = 1;
		game->ray.intersection.x = (game->player->int_pos_x + 1
				- game->player->pos.x) * game->ray.delta.x;
	}
	if (game->ray.direction.y < 0)
	{
		game->ray.map_mov.y = -1;
		game->ray.intersection.y = (game->player->pos.y
				- game->player->int_pos_y) * game->ray.delta.y;
	}
	else
	{
		game->ray.map_mov.y = 1;
		game->ray.intersection.y = (game->player->int_pos_y + 1
				- game->player->pos.y) * game->ray.delta.y;
	}
}

void	ft_cast_a_ray(t_game *game, int i)
{
	double	plane_var;

	plane_var = 2 * i / (double)WIDTH - 1;
	game->ray.direction.x = game->player->dir.x
		+ game->player->plane.pos.x * plane_var;
	game->ray.direction.y = game->player->dir.y
		+ game->player->plane.pos.y * plane_var;
	game->ray.delta.x = fabs(1 / game->ray.direction.x);
	game->ray.delta.y = fabs(1 / game->ray.direction.y);
	game->player->int_pos_x = (int)game->player->pos.x;
	game->player->int_pos_y = (int)game->player->pos.y;
	ft_ray_intersections(game);
}

void	ft_dda(t_game *game)
{
	int	hit_flag;

	hit_flag = false;
	while (!hit_flag)
	{
		if (game->ray.intersection.x < game->ray.intersection.y)
		{
			game->ray.intersection.x += game->ray.delta.x;
			game->player->int_pos_x += game->ray.map_mov.x;
			game->ray.hit_vertical = true;
		}
		else
		{
			game->ray.intersection.y += game->ray.delta.y;
			game->player->int_pos_y += game->ray.map_mov.y;
			game->ray.hit_vertical = false;
		}
		if (game->map->map_matrix[game->player->int_pos_y]
			[game->player->int_pos_x] == '1')
			hit_flag = true;
	}
}

void	ft_distance_to_the_wall(t_game *game)
{
	if (game->ray.hit_vertical == true)
		game->ray.perp_wall_dist = (game->ray.intersection.x
				- game->ray.delta.x);
	else
		game->ray.perp_wall_dist = (game->ray.intersection.y
				- game->ray.delta.y);
	if (game->ray.perp_wall_dist < 0.0001)
		game->ray.perp_wall_dist = 0.0001;
	game->img_info.line_height = fabs((HEIGHT / game->ray.perp_wall_dist));
	game->img_info.draw_start = HEIGHT / 2 - game->img_info.line_height / 2;
	if (game->img_info.draw_start < 0)
		game->img_info.draw_start = 0;
	game->img_info.draw_end = HEIGHT / 2 + game->img_info.line_height / 2;
	if (game->img_info.draw_end >= HEIGHT)
		game->img_info.draw_end = HEIGHT;
	game->img_info.scale = SPRITE_SIZE / game->img_info.line_height;
	game->img_info.pos_texture = (game->img_info.draw_start - (int)HEIGHT / 2
			+ game->img_info.line_height / 2) * game->img_info.scale;
}

void	ft_raycast(t_game *game)
{
	int	i;

	i = -1;
	game->ray.hit_vertical = false;
	while (++i <= ((int)WIDTH - 1))
	{
		ft_cast_a_ray(game, i);
		ft_dda(game);
		ft_distance_to_the_wall(game);
		texture_calc(game);
		ft_color(game, i, 'c');
		ft_textures(game, i);
		ft_color(game, i, 'f');
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}
