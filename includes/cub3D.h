/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeutsch <sdeutsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:47:35 by sdeutsch          #+#    #+#             */
/*   Updated: 2024/07/23 18:14:46 by sdeutsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../srcs/gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>
# include <X11/X.h>

# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define TILE_SIZE 64
# define FOV 60
# define PI  3.14159265358979323846
# define R_SPEED 0.09
# define P_SPEED 10

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
	float	fov;
	int		rot;
	int		l_r;
	int		u_d;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		horizontal_wall;
	int		index;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
}	t_ray;

typedef struct s_image
{
	void	*fti;
	void	*img_p;
	char	*gda;
	int		width;
	int		height;
	int		line_len;
	int		bit_pp;
	int		edn;
}			t_image;

typedef struct s_data
{
	char		**map;
	char		**map2d;
	int			p_x;
	int			p_y;
	int			w_map2d;
	int			h_map2d;
	int			map_height;
	char		cardinals[6][4];
	char		*xpm_path[6];
	void		*init;
	void		*win;
	t_image		*new_image;
	t_image		*sprites;
	t_player	*player;
	t_ray		*ray;

}			t_data;

// ==== INIT_DATA ====

void		init_data(t_data *data);

// ==== PARSING ====

void		parser(t_data *data, int argc, char **argv);
void		get_wall_xpm(t_data *data);
void		get_map2d(t_data *data);
void		set_player(t_data *data);
void		init_ray(t_data *data);
void		check_map(t_data *data);
void		is_existing(t_data *data, char *xpm_path);
void		check_xpm(t_data *data, char *xpm_path);
int			check_countinstr(t_data *data, int *count_instr);
void		check_btlines(t_data *data);
void		check_mapisclosed(t_data *data, int i, int j);
void		check_rlline(t_data *data);

// ==== MLX_CALLS ====

void		init_window(t_data *data);
void		init_sprites(t_data *data);
int			ft_hook(t_data data);
void		new_image(t_data *data);

// ==== EXIT ====

void		free_all(t_data *data);
void		exit_free(t_data *data, int exit_code, char *message);

// ==== EXECUTION ====

float		get_h_inter(t_data *data);
float		get_v_inter(t_data *data);
double		nor_angle(double angle);
void		cast_rays(t_data *data);
void		render_wall(t_data *data);
void		move_player(t_data *data, double move_x, double move_y);
int			rgb_string_to_color(const char *rgb_str);
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
int			return_dir(double move);

#endif
