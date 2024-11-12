/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*fill_res(char c, char *res)
{
	while (*res)
		res++;
	*res = c;
	return (res);
}

static void	ft_putnbr(int n, char *res)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		res = fill_res('-', res);
		ln = -ln;
	}
	if (ln < 10)
		res = fill_res(ln + 48, res);
	if (ln >= 10)
	{
		ft_putnbr(ln / 10, res);
		res = fill_res((ln % 10) + 48, res);
	}
}

char	*ft_itoa(int n)
{
	char	*res;

	res = malloc((num_len(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_bzero(res, (num_len(n) + 1));
	ft_putnbr(n, res);
	return (res);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *res = ft_itoa(0);
    //ft_print_result(res);
	printf("res is : %s", res);
    free(res);
	//printf("num length of %d is %d\n", i, num_len(i));
	//printf("ft_itoa of %d is %s\n", i, ft_itoa(0));
	//printf("itoa of %d is %s\n", i, itoa(0));

}
*/