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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	destlen;

	destlen = ft_strlen(dst);
	i = 0;
	if (dstsize <= destlen)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && i < (dstsize - destlen - 1))
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	srcnat[] = "ca va";
	char	destnat[20] = "salut ";
	char	srcft[] = "ca va";
	char	destft[20] = "salut ";
	int n = 14;

	printf("nat is : %zu\n", strlcat(destnat, srcnat, n));
	printf("ft_ is : %zu\n", ft_strlcat(destft, srcft, n));
	printf("after function, nat dest is : %s\n", destnat);
	printf("after function, ft_ dest is : %s\n", destft);
}
*/