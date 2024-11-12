/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_09_draw_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:19 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:31 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_pixel_from_coordinates(t_data *p_img, t_map_var *var, int *color)
{
	int	iso_x;
	int	iso_y;

	get_p_coord(var, &iso_x, &iso_y);
	ft_pput(p_img, iso_x, iso_y, *color);
	return (1);
}

void	get_p_coord(t_map_var *var, int *iso_x, int *iso_y)
{
	int	x;
	int	y;
	int	temp_z;

	x = ((0.9 * 10 * (var->x)) + (-0.9 * 10 * (var->y)));
	y = ((-0.5 * 10 * (var->x)) + (-0.5 * 10 * (var->y)));
	x = (x * var->space) / 10;
	y = (y * var->space) / 10;
	y = -y;
	x += var->x_offset;
	y += var->y_offset;
	temp_z = var->z;
	y = y - (temp_z * var->z_ratio);
	*iso_x = x;
	*iso_y = y;
}

void	get_p_coord_pt2(t_map_var *var, int *iso_x2, int *iso_y2)
{
	int	x;
	int	y;
	int	temp_z;

	x = ((0.9 * (var->x2 * 10)) + (-0.9 * (var->y2 * 10)));
	y = ((-0.5 * (var->x2 * 10)) + (-0.5 * (var->y2 * 10)));
	x = (x * var->space) / 10;
	y = (y * var->space) / 10;
	y = -y;
	x += var->x_offset;
	y += var->y_offset;
	temp_z = var->z2;
	y = y - (temp_z * var->z_ratio);
	*iso_x2 = x;
	*iso_y2 = y;
}

void	ft_pput(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 1280 && y < 720)
	{
		dst = data->addr + (
				y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
