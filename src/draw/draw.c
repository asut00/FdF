/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_08_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:17 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:28 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *data, t_map_var *var, t_point **point_tab)
{
	draw_pixels(data, var, point_tab);
	draw_lines(data, var, point_tab);
	draw_columns(data, var, point_tab);
}

int	draw_pixels(t_data *p_img, t_map_var *var, t_point **point_tab)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < var->num_of_lines)
	{
		x = 0;
		while (x < var->num_of_points_per_line)
		{
			var->x = x;
			var->y = y;
			var->z = point_tab[x][y].z;
			color = point_tab[x][y].color;
			create_pixel_from_coordinates(p_img, var, &color);
			x++;
		}
		y++;
	}
	return (1);
}

int	draw_lines(t_data *p_img, t_map_var *var, t_point **point_tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < var->num_of_lines)
	{
		x = 0;
		while (x < var->num_of_points_per_line - 1)
		{
			var->x = x;
			var->y = y;
			var->z = point_tab[x][y].z;
			var->col1 = point_tab[x][y].color;
			var->x2 = x + 1;
			var->y2 = var->y;
			var->z2 = point_tab[x + 1][y].z;
			var->col2 = point_tab[x + 1][y].color;
			draw_line_between_2_points(p_img, var);
			x++;
		}
		y++;
	}
	return (1);
}

int	draw_columns(t_data *p_img, t_map_var *var, t_point **point_tab)
{
	int	x;
	int	y;

	x = 0;
	while (x < var->num_of_points_per_line)
	{
		y = 0;
		while (y < var->num_of_lines - 1)
		{
			var->x = x;
			var->y = y;
			var->z = point_tab[x][y].z;
			var->col1 = point_tab[x][y].color;
			var->x2 = x;
			var->y2 = y + 1;
			var->z2 = point_tab[x][y + 1].z;
			var->col2 = point_tab[x][y + 1].color;
			draw_column_between_2_points(p_img, var);
			y++;
		}
		x++;
	}
	return (1);
}
