/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		c += 32;
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_char = 'a'; // Caractère à tester
	printf("enter char : ");
	scanf("%c", &test_char);

    // Utilisation de ft_tolower
    int result_ft = ft_tolower(test_char);

    // Utilisation de tolower (fonction native)
    int result_native = tolower(test_char);

    // Affichage des résultats
    printf("Résultat de ft_tolower : %c\n", (char)result_ft);
    printf("Résultat de tolower : %c\n", (char)result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/