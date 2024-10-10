/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:23:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 15:09:08 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int init_struct(t_game *game)
{
    *game = (t_game){0}; // Inicializa a estrutura t_game
    game->map = (t_map *)malloc(sizeof(t_map));
    if (!game->map)
        return (1);
    *game->map = (t_map){0}; // Inicializa a estrutura t_map
	game->map->width = SCREEN_WIDTH;  // Defina a largura do mapa
    game->map->n_lines = SCREEN_HEIGHT; // Defina a altura do mapa
	game->map->map_matrix = (char **)malloc(game->map->n_lines * sizeof(char *));
    game->player = (t_player *)malloc(sizeof(t_player));
    if (!game->player)
        return (1);
    *game->player = (t_player){0}; // Inicializa a estrutura t_player
	game->player->pos.x = (double)game->player->init_pos_x;
	game->player->pos.y = (double)game->player->init_pos_y;
    game->texture = (t_render *)malloc((int)NBR_TEXTURES * sizeof(t_render));
    if (!game->texture)
        return (1);
    int i = 0;
    while (i < NBR_TEXTURES)
    {
        game->texture[i] = (t_render){0}; // Inicializa cada elemento de t_render
        i++;
    }
    return (0);
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
	init_struct(&game);
	if (check_and_parse(&game, argv) != 0)
		ft_print_err("Error: ");
	init_mlx_and_textures(&game);
	//draw_rays(&game);
	setup(&game);
	mlx_hook(game.render.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.render.win, 3, 1L << 1, &key_release, &game);
	mlx_hook(game.render.win, 17, 1L << 0, &free_structs, &game);
	mlx_loop_hook(game.render.mlx, &draw_rays, &game);
	mlx_loop(game.render.mlx);
	free_structs(&game);
	return (0);
}
