/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:22:20 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/23 09:45:53 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	end_game(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i++ < game->map->n_lines)
		free(game->map->map_matrix[++j]);
	free (game->map->map_matrix);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(game->mlx, game->render[i].image.img_ptr);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_keypress(int keycode, t_game *game)
{
	game->key = keycode;
	if (game->key == ESC)
		end_game(game);
	if (game->key == W)
		game->player->movement.y = 1;
	if (game->key == S)
		game->player->movement.y = -1;
	if (game->key == A)
		game->player->movement.x = -1;
	if (game->key == D)
		game->player->movement.x = 1;
	if (game->key == LEFT)
		game->player->angle = -1;
	if (game->key == RIGHT)
		game->player->angle = 1;
	return (EXIT_SUCCESS);
}

int	ft_keyrelease(int keycode, t_game *game)
{
	game->key = keycode;
	if (game->key == W || game->key == S)
		game->player->movement.y = 0;
	if (game->key == A || game->key == D)
		game->player->movement.x = 0;
	if (game->key == LEFT || game->key == RIGHT)
		game->player->angle = 0;
	return (EXIT_SUCCESS);
}
