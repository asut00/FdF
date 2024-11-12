/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_10_draw_lines_01.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:21 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:33 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line_between_2_points(t_data *p_img, t_map_var *var)
{
	t_duo	duo;

	get_p_coord(var, &duo.iso_x, &duo.iso_y);
	get_p_coord_pt2(var, &duo.iso_x2, &duo.iso_y2);
	join_two_points_in_line(p_img, duo, var);
	return (1);
}

int	join_two_points_in_line(t_data *p_img, t_duo duo, t_map_var *var)
{
	t_jvar	jv;

	init_jvars(&jv, &duo);
	if (jv.abs_y_dist > jv.abs_x_dist)
	{
		if (jv.abs_y_dist)
			jv.col_p = (var->col1 - var->col2) / (jv.abs_y_dist);
		if (duo.iso_y2 - duo.iso_y > 0)
			y_handle_lower_y2(&jv, p_img, &duo, var);
		else
			y_handle_higher_y2(&jv, p_img, &duo, var);
	}
	else if (jv.abs_x_dist >= jv.abs_y_dist)
	{
		if (jv.abs_x_dist)
			jv.col_p = (var->col1 - var->col2) / (jv.abs_x_dist);
		if (jv.ptd_y == duo.iso_y2)
			x_handle_straight_line(&jv, p_img, &duo, var);
		else
			x_handle_else(&jv, p_img, &duo, var);
	}
	return (1);
}

void	init_jvars(t_jvar *jv, t_duo *duo)
{
	jv->abs_x_dist = ft_abs(duo->iso_x2 - duo->iso_x);
	jv->abs_y_dist = ft_abs(duo->iso_y2 - duo->iso_y);
	jv->ptd_x = duo->iso_x;
	jv->ptd_y = duo->iso_y;
	jv->dist_p = 0;
	jv->col_p = 1;
}

void	y_handle_lower_y2(t_jvar	*jv, t_data *p_img,
							t_duo *duo, t_map_var *var)
{
	jv->rest = 1;
	if (jv->abs_x_dist)
		jv->rest = jv->abs_y_dist % jv->abs_x_dist;
	jv->k = 1;
	while (jv->ptd_x != duo->iso_x2 && jv->ptd_y != duo->iso_y2)
	{
		jv->moves_per_ldu = jv->abs_y_dist / jv->abs_x_dist;
		y_handle_lower_y2_loop(jv, p_img, duo, var);
		jv->ptd_x++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
	}
}

void	y_handle_lower_y2_loop(t_jvar	*jv, t_data *p_img,
								t_duo *duo, t_map_var *var)
{
	while (jv->ptd_x != duo->iso_x2
		&& jv->ptd_y != duo->iso_y2 && jv->moves_per_ldu > 0)
	{
		jv->ptd_y++;
		jv->dist_p++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
		jv->moves_per_ldu--;
		if (jv->rest && jv->dist_p >= (((jv->abs_y_dist * jv->k) / jv->rest)))
		{
			jv->ptd_y++;
			jv->dist_p++;
			ft_pput(p_img, jv->ptd_x, jv->ptd_y,
				(var->col1 - ((jv->dist_p) * jv->col_p)));
			jv->k++;
		}
	}
}
