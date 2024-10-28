/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:23:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/28 15:15:20 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



// void	init_textures(t_game *game)
// {
// 	game->render[0] = set_images(game, game->map->no_texture);
// 	game->render[1] = set_images(game, game->map->so_texture);
// 	game->render[2] = set_images(game, game->map->we_texture);
// 	game->render[3] = set_images(game, game->map->ea_texture);
// }

void init_structs (t_game *game)
{
	*game = (t_game){0};
	game->map = malloc(sizeof(t_map));
	memset(game->map, 0, sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	memset(game->player, 0, sizeof(t_player));
	memset(&game->ray, 0, sizeof(t_dda));
	game->ray.hit = false;
	// game->screen = (t_render *)malloc(sizeof(t_render));
	// memset(game->texture, 0, sizeof(t_render));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_print_err("Invalid number of arguments: try ./cub3d <path to map>.");
		return (1);
	}
	argv = argv + 1;
	
	init_structs(&game);
	game.mlx = mlx_init();
	
		
	
	
	if (check_and_parse(&game, argv) == 0)
	{
		init_mlx_and_textures(&game);
		// load_textures(&game);
		// game.win = mlx_new_window(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
		// mlx_hook(game.win, DestroyNotify, ButtonPressMask, end_game, &game);
		//  mlx_hook(game.win, KeyPress, KeyPressMask, ft_keypress, &game);
		//  mlx_hook(game.win, KeyRelease, KeyReleaseMask, ft_keyrelease,&game);
		mlx_hook(game.win, 2, 1L << 0, &key_press, &game);
		mlx_hook(game.win, 3, 1L << 1, &key_release, &game);
		mlx_hook(game.win, 17, 1L << 0, &end_game, &game);
		setup(&game);
		mlx_loop_hook(game.mlx, &draw_rays, &game);
		// mlx_loop_hook(game.mlx, make_game, &game);
		mlx_loop(game.mlx);
	}

	
	
	
	return (0);
}
