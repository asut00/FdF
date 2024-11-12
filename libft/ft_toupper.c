/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c -= 32;
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_char = 'a'; // Caractère à tester
	printf("enter char : ");
	scanf("%c", &test_char);

    // Utilisation de ft_toupper
    int result_ft = ft_toupper(test_char);

    // Utilisation de toupper (fonction native)
    int result_native = toupper(test_char);

    // Affichage des résultats
    printf("Résultat de ft_toupper : %c\n", (char)result_ft);
    printf("Résultat de toupper : %c\n", (char)result_native);

    // Vérification de l'égalité des résultats
    if (result_ft == result_native) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }

    return 0;
}
*/