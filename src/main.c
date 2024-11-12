/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_00_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:14:44 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_map_var	var;
	t_point		**point_tab;

	checks(argc, argv, &data);
	init_map_vars(&var, &data);
	init_scale_vars(&var, &data);
	init_mlx_vars(&var, &data);
	make_point_tab(&data, &var, &point_tab);
	draw(&data, &var, point_tab);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	free_point_tab(point_tab, var.num_of_points_per_line);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 1L << 3, close_prog, &data);
	mlx_loop(data.mlx_ptr);
}
