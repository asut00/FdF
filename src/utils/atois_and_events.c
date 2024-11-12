/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_14_atois_and_events.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:29 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:41 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_spe(const char *str, int *i, int *color)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (str[*i] && (str[*i] == 32 || (9 <= str[*i] && str[*i] <= 13)))
		*i = *i + 1;
	while (str[*i] && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			sign = sign * -1;
		*i = *i + 1;
	}
	while (str[*i] && '0' <= str[*i] && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	if (str[*i] == ',')
		*color = ft_atoi_hex(str, i);
	return (res * sign);
}

int	ft_atoi_hex(const char *str, int *i)
{
	int	res;

	res = 0;
	if (str[*i] == ',' && str[*i + 1] == '0'
		&& (str[*i + 2] == 'x' || str[*i + 2] == 'X'))
		*i += 3;
	while (str[*i] && str[*i] != ' ' && str[*i] != '\n')
	{
		res = res * 16;
		if ('0' <= str[*i] && str[*i] <= '9')
			res += str[*i] - '0';
		else if ('a' <= str[*i] && str[*i] <= 'f')
			res += str[*i] - 'a' + 10;
		else if ('A' <= str[*i] && str[*i] <= 'F')
			res += str[*i] - 'A' + 10;
		(*i)++;
	}
	return (res);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 0xff1b)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (0);
}

int	close_prog(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}
