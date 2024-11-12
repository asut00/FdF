/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_06_init_scale_and_mlx_vars.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:13 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:24 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_scale_vars(t_map_var *var, t_data *data)
{
	double	x_space;
	double	y_space;

	var->win_width = 1280;
	var->win_height = 720;
	x_space = (1 * var->win_width)
		/ (double)(1.5 * var->num_of_points_per_line);
	y_space = (1 * var->win_height) / (double)(1.5 * var->num_of_lines);
	if (x_space == 0)
		x_space = 1;
	if (y_space == 0)
		y_space = 1;
	if (x_space <= y_space)
		var->space = x_space;
	else
		var->space = y_space;
	var->x_offset = 0;
	var->y_offset = 0;
	get_max_iso_values(var, data->map_str);
	var->x_offset = ft_abs(((var->win_width - (
						var->mx_p_x - var->mn_p_x)) / 2) - var->mn_p_x);
	var->y_offset = ft_abs(((var->win_height - (
						var->mx_p_y - var->mn_p_y)) / 2) - var->mn_p_y);
}

int	get_max_iso_values(t_map_var *var, char *map_str)
{
	int	i;
	int	color;

	var->map_str_len = ft_strlen(map_str);
	var->x = 0;
	var->y = 0;
	var->mx_p_x = 0;
	var->mx_p_y = 0;
	var->mn_p_x = 2147483647;
	var->mn_p_y = 2147483647;
	i = 0;
	while (map_str[i] && i < var->map_str_len - 1)
	{
		color = 0xFFFFFF;
		var->z = ft_atoi_spe(map_str, &i, &color);
		get_max_iso_values_from_coordinates(var);
		var->x++;
		if (var->x == var->num_of_points_per_line)
		{
			var->x = 0;
			var->y++;
		}
	}
	return (1);
}

int	get_max_iso_values_from_coordinates(t_map_var *var)
{
	int	iso_x;
	int	iso_y;

	get_p_coord(var, &iso_x, &iso_y);
	if (iso_x > var->mx_p_x)
		var->mx_p_x = iso_x;
	if (iso_y > var->mx_p_y)
		var->mx_p_y = iso_y;
	if (iso_x < var->mn_p_x)
		var->mn_p_x = iso_x;
	if (iso_y < var->mn_p_y)
		var->mn_p_y = iso_y;
	return (1);
}

void	init_mlx_vars(t_map_var *var, t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data->map_str);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, var->win_width,
			var->win_height, "Fdf");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->map_str);
		exit(1);
	}
	init_img_and_address(var, data);
}

void	init_img_and_address(t_map_var *var, t_data *data)
{
	data->img = mlx_new_image(data->mlx_ptr, var->win_width, var->win_height);
	if (!data->img)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->map_str);
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
