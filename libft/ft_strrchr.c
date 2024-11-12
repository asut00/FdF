/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[len]);
	while (0 <= len)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char test_str[] = "hello world"; // Chaîne de caractères à tester
    int test_char = 'o'; // Caractère à chercher

    // Utilisation de ft_strrchr
    char *result_ft = ft_strrchr(test_str, test_char);

    // Utilisation de strrchr (fonction native)
    char *result_native = strrchr(test_str, test_char);

    // Affichage des résultats
    printf("Résultat de ft_strrchr : %s\n", result_ft);
    printf("Résultat de strrchr : %s\n", result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/