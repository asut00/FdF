/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_07_point_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:15 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:14:04 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_point_tab(t_data *data, t_map_var *var, t_point ***point_tab)
{
	*point_tab = put_mapstr_in_tab(data->map_str, var);
	free(data->map_str);
	if (!point_tab)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
}

t_point	**put_mapstr_in_tab(char *str, t_map_var *var)
{
	int		i;
	t_point	**point_tab;

	point_tab = malloc(sizeof(t_point) * var->num_of_points_per_line);
	if (!point_tab)
		return (NULL);
	i = 0;
	while (i < var->num_of_points_per_line)
	{
		point_tab[i] = malloc(sizeof(t_point) * var->num_of_lines);
		if (!point_tab[i])
		{
			free_previous(point_tab, &i);
			free(point_tab);
			return (NULL);
		}
		i++;
	}
	point_tab = fill_point_tab(str, var, point_tab);
	return (point_tab);
}

int	free_previous(t_point **point_tab, int *i)
{
	(*i)--;
	while (*i >= 0)
	{
		free(point_tab[*i]);
		(*i)--;
	}
	return (1);
}

t_point	**fill_point_tab(char *str, t_map_var *var, t_point **point_tab)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (y < var->num_of_lines)
	{
		x = 0;
		while (x < var->num_of_points_per_line)
		{
			point_tab[x][y].color = 0xFFFFFF;
			point_tab[x][y].z = ft_atoi_spe(str, &i, &point_tab[x][y].color);
			x++;
		}
		y++;
	}
	return (point_tab);
}

int	free_point_tab(t_point **point_tab, long i)
{
	i--;
	while (i >= 0)
	{
		free(point_tab[i]);
		i--;
	}
	free(point_tab);
	return (1);
}
