/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:16:22 by migupere          #+#    #+#             */
/*   Updated: 2024/09/26 11:43:03 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = 1;
	else if (keycode == A)
		game->key.a = 1;
	else if (keycode == S)
		game->key.s = 1;
	else if (keycode == D)
		game->key.d = 1;
	else if (keycode == LEFT)
		game->key.left = 1;
	else if (keycode == RIGHT)
		game->key.right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->key.w = 0;
	else if (keycode == A)
		game->key.a = 0;
	else if (keycode == S)
		game->key.s = 0;
	else if (keycode == D)
		game->key.d = 0;
	else if (keycode == LEFT)
		game->key.left = 0;
	else if (keycode == RIGHT)
		game->key.right = 0;
	else if (keycode == ESC)
		game->key.esc += 1;
	return (0);
}
