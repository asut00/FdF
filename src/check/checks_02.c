/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_02_checks_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:07 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char *map_str)
{
	if (!one_line_check(map_str))
	{
		write(2, "Error: Map must contain more than one line\n", 43);
		free(map_str);
		exit(1);
	}
	if (!check_map_format(map_str))
	{
		write(2, "Error: Map format error\n", 24);
		free(map_str);
		exit(1);
	}
	if (!check_points_in_lines(map_str))
	{
		write(2, "Error: Number of points per line is variable\n", 45);
		free(map_str);
		exit(1);
	}
	if (!check_only_int(map_str))
	{
		write(2, "Error: Z bigger than int max\n", 29);
		free(map_str);
		exit(1);
	}
	return (1);
}

int	one_line_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	if (!s[i])
		return (0);
	return (1);
}

int	check_map_format(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!check_map_format_z(s, &i))
			return (0);
		if (s[i] && s[i] == ',')
		{
			if (!s[i + 1] || !s[i + 2] || !s[i + 3])
				return (0);
			if (!(s[i + 1] == '0' && (s[i + 2] == 'x' || s[i + 2] == 'X')))
				return (0);
			i = i + 3;
			skip_hex_num(s, &i);
		}
		if (s[i] && !(s[i] == ' ' || s[i] == '\n'))
			return (0);
	}
	return (1);
}

int	check_map_format_z(char *s, int *i)
{
	skip_spaces_and_nl(s, i);
	if (s[*i] && s[*i] == '-')
		(*i)++;
	if (s[*i] && !('0' <= s[*i] && s[*i] <= '9'))
		return (0);
	while (s[*i] && ('0' <= s[*i] && s[*i] <= '9'))
		(*i)++;
	return (1);
}

void	skip_spaces_and_nl(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\n'))
		(*i)++;
}
