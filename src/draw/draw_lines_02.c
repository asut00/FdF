/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_11_draw_lines_02.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:23 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:35 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	y_handle_higher_y2(t_jvar	*jv, t_data *p_img,
							t_duo *duo, t_map_var *var)
{
	jv->rest = 1;
	if (jv->abs_x_dist)
		jv->rest = jv->abs_y_dist % jv->abs_x_dist;
	jv->k = 1;
	while (jv->ptd_x != duo->iso_x2 && jv->ptd_y != duo->iso_y2)
	{
		jv->moves_per_ldu = jv->abs_y_dist / jv->abs_x_dist;
		y_handle_higher_y2_loop(jv, p_img, duo, var);
		jv->ptd_x++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
	}
}

void	y_handle_higher_y2_loop(t_jvar	*jv, t_data *p_img,
								t_duo *duo, t_map_var *var)
{
	while (jv->ptd_x != duo->iso_x2
		&& jv->ptd_y != duo->iso_y2 && jv->moves_per_ldu > 0)
	{
		jv->ptd_y--;
		jv->dist_p++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
		jv->moves_per_ldu--;
		if (jv->rest && jv->dist_p >= (((jv->abs_y_dist * jv->k) / jv->rest)))
		{
			jv->ptd_y--;
			jv->dist_p++;
			ft_pput(p_img, jv->ptd_x, jv->ptd_y,
				(var->col1 - ((jv->dist_p) * jv->col_p)));
			jv->k++;
		}
	}
}

void	x_handle_straight_line(t_jvar	*jv, t_data *p_img,
								t_duo *duo, t_map_var *var)
{
	while (jv->ptd_x != duo->iso_x2)
	{
		jv->ptd_x++;
		jv->dist_p++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
	}
}

void	x_handle_else(t_jvar *jv, t_data *p_img, t_duo *duo, t_map_var *var)
{
	jv->rest = 1;
	if (jv->abs_y_dist)
		jv->rest = jv->abs_x_dist % jv->abs_y_dist;
	jv->k = 1;
	while (jv->ptd_x != duo->iso_x2 && jv->ptd_y != duo->iso_y2)
	{
		jv->moves_per_ldu = jv->abs_x_dist / jv->abs_y_dist;
		x_handle_else_loop(jv, p_img, duo, var);
		if (jv->ptd_y < duo->iso_y2)
			jv->ptd_y++;
		else if (jv->ptd_y > duo->iso_y2)
			jv->ptd_y--;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
	}
}

void	x_handle_else_loop(t_jvar *jv, t_data *p_img,
							t_duo *duo, t_map_var *var)
{
	while (jv->ptd_x != duo->iso_x2
		&& jv->ptd_y != duo->iso_y2 && jv->moves_per_ldu > 0)
	{
		jv->ptd_x++;
		jv->dist_p++;
		ft_pput(p_img, jv->ptd_x, jv->ptd_y,
			(var->col1 - ((jv->dist_p) * jv->col_p)));
		jv->moves_per_ldu--;
		if (jv->rest && jv->dist_p >= (((jv->abs_x_dist * jv->k) / jv->rest)))
		{
			jv->ptd_x++;
			jv->dist_p++;
			ft_pput(p_img, jv->ptd_x, jv->ptd_y,
				(var->col1 - ((jv->dist_p) * jv->col_p)));
			jv->k++;
		}
	}
}
