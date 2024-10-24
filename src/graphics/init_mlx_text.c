/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:51:15 by migupere          #+#    #+#             */
/*   Updated: 2024/10/24 17:34:17 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_init(void *ptr, t_game *game, const char *error_message)
{
	if (!ptr)
		ft_perror((char *)error_message, game);
}

void	load_textures(t_game *game)
{
	int		i;
	char	**texture_paths =(char **)malloc((int)NBR_TEXTURES * sizeof(char *));

	i = 0;
	texture_paths[0] = game->map->no_texture;
	texture_paths[1] = game->map->ea_texture;
	texture_paths[2] = game->map->we_texture;
	texture_paths[3] = game->map->so_texture;
	while (i < 4)
	{
		game->render[i].img = mlx_xpm_file_to_image(game->mlx,
				texture_paths[i], &game->render[i].width,
				&game->render[i].height);
		if (!game->render[i].img)
			ft_perror("Failed to load texture", game);
		game->render[i].addr = mlx_get_data_addr(game->render[i].img,
				&game->render[i].bpp, &game->render[i].line_len,
				&game->render[i].endian);
		if (!game->render[i].addr)
			ft_perror("Failed to get texture address", game);
		i++;
	}
	free(texture_paths);
}

void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	check_init(game->mlx, "Failed to initialize mlx", game);
	load_textures(game);
	game->screen.width = (int)SCREEN_WIDTH;
	game->screen.height = (int)SCREEN_HEIGHT;
	game->screen.img = mlx_new_image(game->mlx,
			game->screen.width, game->screen.height);
	check_init(game->screen.img, "Failed to create new image", game);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bpp, &game->screen.line_len, &game->screen.endian);
	check_init(game->screen.addr, "Failed to get image address", game);
	game->win = mlx_new_window(game->mlx, game->screen.width,
			game->screen.height, "CUB3D");
	check_init(game->win, "Failed to create new window", game);
}
