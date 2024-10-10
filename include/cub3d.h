/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:58:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/10 14:33:30 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <math.h>
# include <errno.h>
# include <stdint.h>

# define BUFF 50
# define NBR_TEXTURES 4
# define DIRECTIONS "NO,SO,EA,WE"
# define COLOR_PLACE "F ,C "
# define W 119
# define A 97
# define S 115
# define D 100
# define P 112
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define RESET "\033[0m"
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4
# define PI 3.141592653589793

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_dda
{
	double		camera_x;
	t_vector	ray_dir;
	t_vector	pixel;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_coord		map_pos;
	t_coord		step;
	int			hit;
	int			side;
	double		perp_wall_dist;
}	t_dda;

typedef struct s_player
{
	int			init_pos_x;
	int			init_pos_y;
	char		fov; // field of view
	t_vector	dir;
	t_vector	plane;
	double		move_speed;
	double		rot_speed;
	int			img_index;
	double		hit_dist;
	double		hit_x;
	int			pitch;
	t_vector	pos;
}	t_player;

typedef struct s_map
{
	char	**map_matrix;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor[3];
	int		ceiling[3];
	int		n_lines;
	int		width;
}	t_map;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
}	t_keys;

typedef struct s_render
{
	int			start_y;
	int			end_y;
	double		texture_step;
	double		texture_pos;
	void		*img;
	int			width;
	int			height;
	char		*texture[NBR_TEXTURES];
	double		point_x;
	int			texture_x;
	void		*mlx;
	void		*win;
	char		*addr;
	int			line_len;
	int			bpp;
	int			endian;
	t_map		*map;
}	t_render;

typedef struct s_game
{
	char		*file;
	t_map		*map;
	t_player	*player;
	t_keys		key;
	t_render	render;
	t_render	*texture;
}	t_game;

int			check_and_parse(t_game *game, char **path);
int			convert_data_map(t_game *game, char *temp_raw_map);
int			check_tex_path(t_game *game, char **path);
int			parse_map_matrix(char** map_line, t_game *game);
int			flood_fill(char **map_line, t_game *game);
void		draw_walls_and_background(t_dda *ray, t_game *game, int x);

int			error_exit(t_game *game, char *message);
int			free_structs(t_game *game);
void		free_arr(char **arr);
void		ft_print_err(char *err);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			draw_rays(t_game *game);
void		init_mlx_and_textures(t_game *game);
void		draw_wall(t_game *game, t_render *wall, t_render *texture, int x);
void		draw_floor(t_game *game, int x, int start_y);
void		draw_ceiling(t_game *game, int x, int start_y);
bool		is_valid_move(t_game *game, double new_x, double new_y);
void		compute_new_player_position(t_game *game, double *new_x, double *new_y);
t_vector	rotate_vector(t_vector v, float angle);
t_vector	add_vector(t_vector v1, t_vector v2);
t_vector	x_vector(t_vector v, float scalar);
t_vector	create_vector(float x, float y);
void		setup(t_game *game);

#endif
