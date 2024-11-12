/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char test_str[] = "tripouille"; // Chaîne de caractères à tester
    int test_char = ('t' + 256); // Caractère à chercher

    // Utilisation de ft_strchr
    char *result_ft = ft_strchr(test_str, test_char);

    // Utilisation de strchr (fonction native)
    char *result_native = strchr(test_str, test_char);

    // Affichage des résultats
    printf("Résultat de ft_strchr : %s\n", result_ft);
    printf("Résultat de strchr : %s\n", result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/