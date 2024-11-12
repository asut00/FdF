/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_04_checks_04.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:08 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/31 15:13:17 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	atoi_handle_sign(char *str, int *i, int *sign, int *sign_count)
{
	while (str[*i] && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*sign = *sign * -1;
		(*sign_count)++;
		*i = *i + 1;
	}
	if (*sign_count > 1)
		sign_error(str);
}

void	sign_error(char *str)
{
	free(str);
	write(2, "Error: Z sign error\n", 20);
	exit(1);
}

int	ft_atoi_hex_check(char *str, int *i)
{
	int	res;

	res = 0;
	if (!(str[*i] == ',' && str[*i + 1] == '0'
			&& (str[*i + 2] == 'x' || str[*i + 2] == 'X')))
		error_invalid_color(str);
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
		else
			error_invalid_color(str);
		(*i)++;
	}
	return (res);
}

void	error_invalid_color(char *str)
{
	write(2, "Error: Invalid color\n", 32);
	free(str);
	exit(1);
}

char	*delete_extra_nl(char *full_str)
{
	int	i;

	i = 0;
	while (full_str[i])
		i++;
	i--;
	while (full_str[i] == '\n')
	{
		full_str[i] = '\0';
		i--;
	}
	return (full_str);
}
