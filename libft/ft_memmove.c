/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	if (!dst && !src)
		return (NULL);
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (src2 == dst2)
		return (dst);
	if (src2 < dst2)
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
		return (dst);
	}
	else
	{
		while (len--)
			*dst2++ = *src2++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char src[] = "hello";
    char dst1[20];
    char dst2[20];
    size_t len = 6;

    // Utilisation de ft_memmove
    ft_memmove(dst1, src, len);

    // Utilisation de memmove (fonction native)
    memmove(dst2, src, len);
    // Affichage du résultat de ft_memmove
    printf("Résultat de ft_memmove : |%s|\n", dst1);

    // Affichage du résultat de memmove (fonction native)
    printf("Résultat de memmove : |%s|\n", dst2);

    // Comparaison des résultats
	printf("strcmp(dst1, dst2) is : %d\n", strcmp(dst1, dst2));
    if (strcmp(dst1, dst2) == 0) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }
    return 0;
}
*/