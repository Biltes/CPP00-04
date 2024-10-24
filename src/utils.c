/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:52:22 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/24 16:32:47 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_perror(char *msg, t_game *game)
{
	int	i;

	i = -1;
	printf("%s", msg);
	if (!game)
		exit (EXIT_FAILURE);
	while (++i < 4)
	{
		if (game->render[i].img)
			mlx_destroy_image(game->mlx, game->render[i].img);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
	}
	
	if (game->map->map_matrix)
		free_arr(game->map->map_matrix);
	exit (EXIT_SUCCESS);
}