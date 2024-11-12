/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ddst;
	char	*ssrc;

	if (!dst && !src)
		return (dst);
	i = 0;
	ddst = (char *)dst;
	ssrc = (char *)src;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	return (dst);
}

/*
# include <string.h>
# include <stdio.h>

int main() {
    // Données à copier
    char src[100] = "";
	printf("insert string : ");
	scanf("%s", src);
    char dest1[20];
    char dest2[20];

    // Utilisation de ft_memcpy
    ft_memcpy(dest1, src, strlen(src) + 1);

    // Utilisation de memcpy (fonction native)
    memcpy(dest2, src, strlen(src) + 1);

    // Comparaison des résultats
    printf("Résultat de ft_memcpy: %s\n", dest1);
    printf("Résultat de memcpy: %s\n", dest2);

    // Vérification de l'égalité
    if (strcmp(dest1, dest2) == 0) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/