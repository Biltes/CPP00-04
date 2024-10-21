/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:53:22 by migupere          #+#    #+#             */
/*   Updated: 2024/10/20 11:53:36 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	my_pixel_get(t_render *texture, int x, int y)
{
	return (*(unsigned int *)(texture->image.addr + (y * texture->image.line_len)
		+ (x * (texture->image.bpp / 8))));
}

static void	my_pixel_put(t_render *render, int x, int y, int color)
{
	char	*dst;

	dst = render->image.addr + (y * render->image.line_len + x * (render->image.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling(t_game *game, int x, int start_y)
{
	int	y;
	int	ceiling_color;

	y = 0;
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

	y = start_y;
	floor_color = (game->map->floor[0] << 16) | (game->map->floor[1] << 8)
		| game->map->floor[2];
	while (y < HEIGHT)
	{
		my_pixel_put(&game->render, x, y, floor_color);
		y++;
	}
}

void	draw_wall(t_game *game, t_img_info *wall, t_render *texture, int x)
{
	int	y;
	int	text_y;
	int	color;

	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		text_y = (int)wall->pos_texture & (HEIGHT - 1);
		wall->pos_texture += wall->scale;
		color = my_pixel_get(texture, wall->tex_x, text_y);
		my_pixel_put(&game->render, x, y, color);
		y++;
	}
}
