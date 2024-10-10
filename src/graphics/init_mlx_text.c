/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:51:15 by migupere          #+#    #+#             */
/*   Updated: 2024/10/08 14:19:20 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_init(void *ptr, t_game *game, const char *error_message)
{
	if (!ptr)
		error_exit(game, (char *)error_message);
}

void	load_textures(t_game *game)
{
	int		i;
	char	**texture_paths;

	texture_paths =(char **)malloc((int)NBR_TEXTURES * sizeof(char *));
	i = 0;
	texture_paths[0] = game->map->no_texture;
	texture_paths[1] = game->map->ea_texture;
	texture_paths[2] = game->map->we_texture;
	texture_paths[3] = game->map->so_texture;
	while (i < 4)
	{
		game->texture[i].img = mlx_xpm_file_to_image(game->render.mlx,
				texture_paths[i], &game->texture[i].width,
				&game->texture[i].height);
		if (!game->texture[i].img)
			error_exit(game, "Failed to load texture");
		game->texture[i].addr = mlx_get_data_addr(game->texture[i].img,
				&game->texture[i].bpp, &game->texture[i].line_len,
				&game->texture[i].endian);
		if (!game->texture[i].addr)
			error_exit(game, "Failed to get texture address");
		i++;
	}
	free(texture_paths);
}

void	init_mlx_and_textures(t_game *game)
{
	game->render.mlx = mlx_init();
	check_init(game->render.mlx, game, "Failed to initialize mlx");
	load_textures(game);
	game->render.width = (int)SCREEN_WIDTH;
	game->render.height = (int)SCREEN_HEIGHT;
	game->render.img = mlx_new_image(game->render.mlx,
			game->render.width, game->render.height);
	check_init(game->render.img, game, "Failed to create new image");
	game->render.addr = mlx_get_data_addr(game->render.img,
			&game->render.bpp, &game->render.line_len, &game->render.endian);
	check_init(game->render.addr, game, "Failed to get image address");
	game->render.win = mlx_new_window(game->render.mlx, game->render.width,
			game->render.height, "CUB3D");
	check_init(game->render.win, game, "Failed to create new window");
}
