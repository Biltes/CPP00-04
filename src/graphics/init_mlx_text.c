/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:51:15 by migupere          #+#    #+#             */
/*   Updated: 2024/10/20 12:37:27 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_init(void *ptr, t_game *game, const char *error_message)
{
	if (!ptr)
		ft_perror(game, (char *)error_message);
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
		game->render[i].image.img = mlx_xpm_file_to_image(game->mlx,
				texture_paths[i], &game->texture[i].width,
				&game->texture[i].height);
		if (!game->render[i].image.img)
			ft_perror("Failed to load texture", game);
		game->render[i].image.addr = mlx_get_data_addr(game->render[i].image.img,
				&game->render[i].image.bpp, &game->render[i].image.line_len,
				&game->render[i].image.endian);
		if (!game->render[i].image.addr)
			ft_perror("Failed to get texture address", game);
		i++;
	}
	free(texture_paths);
}

void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	check_init("Failed to initialize mlx", game->mlx, game);
	load_textures(game);
	game->render->width = (int)WIDTH;
	game->render->height = (int)HEIGHT;
	game->render->image.img = mlx_new_image(game->mlx,
			game->render->width, game->render->height);
	check_init("Failed to create new image", game->render->image.img, game);
	game->render->image.addr = mlx_get_data_addr(game->render->image.img,
			&game->render->image.bpp, &game->render->image.line_len, &game->render->image.endian);
	check_init("Failed to get image address", game->render->image.addr, game);
	game->win = mlx_new_window(game->mlx, game->render->width,
			game->render->height, "CUB3D");
	check_init("Failed to create new window", game->win, game);
}
