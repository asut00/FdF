/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_03_checks_03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:05 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	skip_hex_num(char *s, int *i)
{
	while (s[*i]
		&& (('0' <= s[*i] && s[*i] <= '9')
			|| ('a' <= s[*i] && s[*i] <= 'f')
			|| ('A' <= s[*i] && s[*i] <= 'F')))
		(*i)++;
}

size_t	check_points_in_lines(const char *s)
{
	size_t	i;
	int		pts_in_fl;
	int		pts_in_l;

	i = 0;
	pts_in_fl = get_points_in_first_line(s);
	pts_in_l = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			i++;
		pts_in_l = 0;
		while (s[i] && s[i] != '\n')
		{
			if (s[i] && s[i] != '\n' && !ft_isspace(s[i]))
				pts_in_l++;
			while (s[i] && s[i] != '\n' && !ft_isspace(s[i]))
				i++;
			while (s[i] && s[i] != '\n' && ft_isspace(s[i]))
				i++;
		}
		if (pts_in_l != pts_in_fl && !(s[i] == '\0' && s[i - 1] == '\n'))
			return (0);
	}
	return (1);
}

int	get_points_in_first_line(const char *s)
{
	size_t	i;
	int		points_in_first_line;

	i = 0;
	points_in_first_line = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] && s[i] != '\n' && !ft_isspace(s[i]))
			points_in_first_line++;
		while (s[i] && s[i] != '\n' && !ft_isspace(s[i]))
			i++;
		while (s[i] && s[i] != '\n' && ft_isspace(s[i]))
			i++;
	}
	return (points_in_first_line);
}

int	check_only_int(char *str)
{
	int		i;
	int		strlen;
	int		fake_color;
	long	z;

	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		z = ft_atoi_check(str, &i, &fake_color);
		if (z < -2147483648 || z > 2147483647)
			return (0);
	}
	return (1);
}

long	ft_atoi_check(char *str, int *i, int *color)
{
	long	res;
	int		sign;
	int		sign_count;

	res = 0;
	sign = 1;
	sign_count = 0;
	while (str[*i] && (str[*i] == 32 || (9 <= str[*i] && str[*i] <= 13)))
		*i = *i + 1;
	atoi_handle_sign(str, i, &sign, &sign_count);
	while (str[*i] && '0' <= str[*i] && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	if (str[*i] == ',')
		*color = ft_atoi_hex_check(str, i);
	return (res * sign);
}
