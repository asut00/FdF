/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	int	n = 2;

	char src[] = "zouu";
	char dst[100];
	//printf("enter n : ");
	//scanf("%d", &n);
	//ft_strlcpy(dst, src, n);
	printf("ft_ src is %s\n", src);
	printf("ft_ return is %zu\n", ft_strlcpy(dst, src, n));
	printf("ft_ dst is %s\n", dst);

	printf("\n");

	char dst2[100];
	printf("nat src is %s\n", src);
	printf("nat return is %zu\n", ft_strlcpy(dst2, src, n));
	printf("nat dst is %s\n", dst2);

	//printf("enter n : ");
	//scanf("%d", &n);
	//ft_strlcpy(dst, src, n);
	//printf("dst of nat is %d\n", strlcpy(dst, src, n));
}
*/