/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    //char test_str[] = "bonjourno"; // Chaîne de caractères à tester
    //int test_char = 'n'; // Caractère à chercher
	//size_t n = 2;

    // Utilisation de ft_memchr
    char *result_ft = ft_memchr("bonjourno", 'n', 2);

    // Utilisation de memchr (fonction native)
    char *result_native = memchr("bonjourno", 'n', 2);

    // Affichage des résultats
    printf("Résultat de ft_memchr : %s\n", result_ft);
    printf("Résultat de memchr : %s\n", result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/
