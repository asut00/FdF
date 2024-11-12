/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/06/07 17:00:48 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//\\//\\//\\//\\//\\//\\//\\// LIBRARIES //\\//\\//\\//\\//\\//\\//\\//

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"

//\\//\\//\\//\\//\\//\\//\\// STRUCTURES //\\//\\//\\//\\//\\//\\//\\//

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map_str;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_map_var
{
	int			x;
	int			y;
	int			z;
	int			x2;
	int			y2;
	int			z2;
	double		space;
	int			map_str_len;
	long		num_of_points_per_line;
	long		num_of_lines;
	long		num_of_points;
	int			win_width;
	int			win_height;
	int			x_offset;
	int			y_offset;
	long		min_z;
	long		max_z;
	long long	z_amp;
	double		z_ratio;
	int			mx_p_x;
	int			mx_p_y;
	int			mn_p_x;
	int			mn_p_y;
	int			col1;
	int			col2;
	float		z_temper;
}				t_map_var;

typedef struct s_duo
{
	int	iso_x;
	int	iso_y;
	int	iso_x2;
	int	iso_y2;
}				t_duo;

typedef struct s_jvar
{
	int	abs_x_dist;
	int	abs_y_dist;
	int	moves_per_ldu;
	int	rest;
	int	ptd_x;
	int	ptd_y;
	int	dist_p;
	int	k;
	int	col_p;
}				t_jvar;

//\\//\\//\\//\\//\\//\\//\\// FUNCTIONS //\\//\\//\\//\\//\\//\\//\\//

// fdf_01_checks_01.c
void	checks(int argc, char **argv, t_data *data);
char	*parse_file_to_str(char *file_path);
int		get_fd(char *file_path);
char	*read_and_cat_str(int fd, char *full_str);
char	*ft_strdup_and_add_string(char *old_s, char *s_to_add, int bytes_read);

// fdf_02_checks_02.c
int		check_map(char *map_str);
int		one_line_check(char *s);
int		check_map_format(char *s);
int		check_map_format_z(char *s, int *i);
void	skip_spaces_and_nl(char *s, int *i);

// fdf_03_checks_03.c
void	skip_hex_num(char *s, int *i);
size_t	check_points_in_lines(const char *s);
int		get_points_in_first_line(const char *s);
int		check_only_int(char *str);
long	ft_atoi_check(char *str, int *i, int *color);

// fdf_04_checks_04.c
void	atoi_handle_sign(char *str, int *i, int *sign, int *sign_count);
void	sign_error(char *str);
int		ft_atoi_hex_check(char *str, int *i);
void	error_invalid_color(char *str);
char	*delete_extra_nl(char *full_str);

// fdf_05_init_map_vars.c
void	init_map_vars(t_map_var *var, t_data *data);
int		ft_get_min_z(char *map_str);
int		ft_get_max_z(char *map_str);
size_t	points_in_line(const char *s);

// fdf_06_init_scale_and_mlx_vars.c
void	init_scale_vars(t_map_var *var, t_data *data);
int		get_max_iso_values(t_map_var *var, char *map_str);
int		get_max_iso_values_from_coordinates(t_map_var *var);
void	init_mlx_vars(t_map_var *var, t_data *data);
void	init_img_and_address(t_map_var *var, t_data *data);

// fdf_07_point_tab.c
void	make_point_tab(t_data *data, t_map_var *var, t_point ***point_tab);
t_point	**put_mapstr_in_tab(char *str, t_map_var *var);
int		free_previous(t_point **point_tab, int *i);
t_point	**fill_point_tab(char *str, t_map_var *var, t_point **point_tab);
int		free_point_tab(t_point **point_tab, long i);

// fdf_08_draw.c
void	draw(t_data *data, t_map_var *var, t_point **point_tab);
int		draw_pixels(t_data *p_img, t_map_var *var, t_point **point_tab);
int		draw_lines(t_data *p_img, t_map_var *var, t_point **point_tab);
int		draw_columns(t_data *p_img, t_map_var *var, t_point **point_tab);

// fdf_09_draw_pixels.c
int		create_pixel_from_coordinates(t_data *p_img,
			t_map_var *var, int *color);
void	get_p_coord(t_map_var *var, int *iso_x, int *iso_y);
void	get_p_coord_pt2(t_map_var *var, int *iso_x2, int *iso_y2);
void	ft_pput(t_data *data, int x, int y, int color);

// fdf_10_draw_lines_01.c
int		draw_line_between_2_points(t_data *p_img, t_map_var *var);
int		join_two_points_in_line(t_data *p_img, t_duo duo, t_map_var *var);
void	init_jvars(t_jvar *jv, t_duo *duo);
void	y_handle_lower_y2(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	y_handle_lower_y2_loop(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);

// fdf_11_draw_lines_02.c
void	y_handle_higher_y2(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	y_handle_higher_y2_loop(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	x_handle_straight_line(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	x_handle_else(t_jvar *jv, t_data *p_img, t_duo *duo, t_map_var *var);
void	x_handle_else_loop(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);

// fdf_12_draw_columns_01.c
int		draw_column_between_2_points(t_data *p_img, t_map_var *var);
int		join_two_points_in_column(t_data *p_img, t_duo duo, t_map_var *var);
void	col_y_handle_higher_y2(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	col_y_handle_higher_y2_loop(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);

// fdf_13_draw_columns_02.c
void	col_y_handle_lower_y2(t_jvar	*jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	col_y_handle_lower_y2_loop(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	col_x_handle_straight_line(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	col_x_handle_else(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);
void	col_x_handle_else_loop(t_jvar *jv, t_data *p_img,
			t_duo *duo, t_map_var *var);

//	fdf_14_atois_and_events.c
int		ft_atoi_spe(const char *str, int *i, int *color);
int		ft_atoi_hex(const char *str, int *i);
int		handle_input(int keysym, t_data *data);
int		close_prog(t_data *data);

#endif