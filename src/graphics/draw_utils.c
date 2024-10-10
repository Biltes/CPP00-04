/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:53:22 by migupere          #+#    #+#             */
/*   Updated: 2024/10/09 14:44:36 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	my_pixel_get(t_render *texture, int x, int y)
{
	return (*(unsigned int *)(texture->addr + (y * texture->line_len)
		+ (x * (texture->bpp / 8))));
}

static void	my_pixel_put(t_render *render, int x, int y, int color)
{
	char	*dst;

	dst = render->addr + (y * render->line_len + x * (render->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling(t_game *game, int x, int start_y)
{
	int	y;
	int	ceiling_color;

	y = 0;
	start_y = SCREEN_HEIGHT / 2;
	ceiling_color = (game->map->ceiling[0] << 16) | (game->map->ceiling[1] << 8)
		| game->map->ceiling[2];
	while (y < start_y)
	{
		my_pixel_put(&game->render, x, y, ceiling_color);
		y++;
	}
}	

void	draw_floor(t_game *game, int x, int start_y)
{
	int	y;
	int	floor_color;

	start_y = SCREEN_HEIGHT / 2;
	y = start_y;
	floor_color = (game->map->floor[0] << 16) | (game->map->floor[1] << 8)
		| game->map->floor[2];
	while (y < SCREEN_HEIGHT)
	{
		my_pixel_put(&game->render, x, y, floor_color);
		y++;
	}
}

void	draw_wall(t_game *game, t_render *wall, t_render *texture, int x)
{
	int	y;
	int	text_y;
	int	color;

	y = wall->start_y;
	while (y < wall->end_y)
	{
		text_y = (int)wall->texture_pos & (TEXTURE_HEIGHT - 1);
		wall->texture_pos += wall->texture_step;
		color = my_pixel_get(texture, wall->texture_x, text_y);
		my_pixel_put(&game->render, x, y, color);
		y++;
	}
}
