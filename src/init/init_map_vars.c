/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_05_init_map_vars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:10 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:20 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map_vars(t_map_var *var, t_data *data)
{
	var->min_z = ft_get_min_z(data->map_str);
	var->max_z = ft_get_max_z(data->map_str);
	var->z_amp = 1;
	if (var->max_z - var->min_z)
		var->z_amp = var->max_z - var->min_z;
	if (var->z_amp < 100)
		var->z_ratio = 100 / (double)var->z_amp;
	else if (var->z_amp >= 100)
		var->z_ratio = 100 * 3 / (double)var->z_amp;
	var->num_of_points_per_line = points_in_line(data->map_str);
	var->num_of_lines = ft_strlines(data->map_str);
	var->num_of_points = var->num_of_points_per_line * var->num_of_lines;
	if (var->num_of_points > 5000000)
	{
		write(2, "Error: Too many points\n", 23);
		free(data->map_str);
		exit(1);
	}
}

int	ft_get_min_z(char *map_str)
{
	int	i;
	int	min_z;
	int	value;
	int	color;

	i = 0;
	value = ft_atoi_spe(map_str, &i, &color);
	min_z = value;
	while (map_str[i])
	{
		value = ft_atoi_spe(map_str, &i, &color);
		if (value < min_z)
			min_z = value;
	}
	return (min_z);
}

int	ft_get_max_z(char *map_str)
{
	int	i;
	int	max_z;
	int	value;
	int	color;

	i = 0;
	value = ft_atoi_spe(map_str, &i, &color);
	max_z = value;
	while (map_str[i])
	{
		value = ft_atoi_spe(map_str, &i, &color);
		if (value > max_z)
			max_z = value;
	}
	return (max_z);
}

size_t	points_in_line(const char *s)
{
	size_t	i;
	int		points;

	i = 0;
	points = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != '\0' && s[i] != '\n' && !ft_isspace(s[i]))
			points++;
		while (s[i] != '\0' && s[i] != '\n' && !ft_isspace(s[i]))
			i++;
		while (s[i] != '\0' && s[i] != '\n' && ft_isspace(s[i]))
			i++;
	}
	return (points);
}
