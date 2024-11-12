/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "test\200";
    char str2[] = "test\0";
    size_t n = 6;

    // Utilisation de ft_strncmp
    int result_ft = ft_strncmp(str1, str2, n);

    // Utilisation de strncmp (fonction native)
    int result_native = strncmp(str1, str2, n);

    // Affichage des résultats
    printf("Résultat de ft_strncmp : %d\n", result_ft);
    printf("Résultat de strncmp : %d\n", result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }
    return 0;
}
*/