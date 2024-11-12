/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;

	while (n-- > 0)
	{
		if (*p1 != *p2)
		{
			if (*p1 != *p2)
				return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char s2[] = "\xff\xaa\xde\xffMACOSX\xff";
	char s3[] = "\xff\xaa\xde\x02";
    size_t n = 8;

    // Utilisation de ft_memcmp
    int result_ft = ft_memcmp(s2, s3, n);

    // Utilisation de memcmp (fonction native)
    int result_native = memcmp(s2, s3, n);

    // Affichage des résultats
    printf("Résultat de ft_memcmp : %d\n", result_ft);
    printf("Résultat de memcmp : %d\n", result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }
    return 0;
}
*/
