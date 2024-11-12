/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (count * size));
	return (mem);
}

/*
#include <stdio.h>
#include <stdlib.h> // Pour calloc
#include <string.h> // Pour memcmp

int main(void)
{
    // Test avec ft_calloc
    size_t count = 5;
    size_t size = sizeof(int);
    int *arr1 = (int *)ft_calloc(count, size);
    if (arr1 == NULL)
    {
        printf("Erreur d'allocation de mémoire avec ft_calloc\n");
        return 1;
    }

    // Initialisation des valeurs de l'array
    for (size_t i = 0; i < count; i++)
        arr1[i] = i + 1;

    // Test avec calloc
    int *arr2 = (int *)calloc(count, size);
    if (arr2 == NULL)
    {
        printf("Erreur d'allocation de mémoire avec calloc\n");
        free(arr1); // Libérer la mémoire allouée par ft_calloc
        return 1;
    }

    // Initialisation des valeurs de l'array
    for (size_t i = 0; i < count; i++)
        arr2[i] = i + 1;

    // Comparaison des deux tableaux
    if (memcmp(arr1, arr2, count * size) == 0)
        printf("Les deux tableaux sont identiques\n");
    else
        printf("Les deux tableaux sont différents\n");

    // Libération de la mémoire
    free(arr1);
    free(arr2);

    return 0;
}
*/