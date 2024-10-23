/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:30:18 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/20 11:42:41 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	pixel_get(t_image *img, int pixel_x, int pixel_y)
{
	int	color;

	color = *(unsigned int *)(img->address + (pixel_y * img->line_length
				+ pixel_x * (img->bits_per_pixel / 8)));
	return (color);
}

void	pixel_put(t_image *img, int pixelX, int pixelY, int color)
{
	char	*dst;
	dst = img->address + (pixelY * img->line_length
			+ pixelX * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_textures(t_game *game, int i)
{
	int	texture;
	int	tex_y;

	while (game->img_info.draw_start < game->img_info.draw_end)
	{
		tex_y = (int)game->img_info.pos_texture & (SPRITE_SIZE - 1);
		game->img_info.pos_texture += game->img_info.scale;
		texture = pixel_get(&game->render[game->texture->index].image,
				game->img_info.tex_x, tex_y);
		pixel_put(&game->img, i, game->img_info.draw_start++, texture);
	}
}

void	ft_color(t_game *game, int i, char flag)
{
	int	y;

	y = -1;
	if (flag == 'c')
	{
		while (++y < game->img_info.draw_start)
			pixel_put(&game->img, i, y, game->map->c_color);
	}
	else if (flag == 'f')
	{
		while (game->img_info.draw_end < (int)HEIGHT)
			pixel_put(&game->img, i,
				game->img_info.draw_end++, game->map->f_color);
	}
}

void	generate_image(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		ft_perror("Error\nmlx_new_image error\n", game);
	game->img.address = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!game->img.address)
		ft_perror("Error\nmlx_get_data_addr\n", game);
}
