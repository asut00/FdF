/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h> // Pour memset
#include <stdlib.h> // Pour malloc

int main(void)
{
    // Test avec ft_memset
    size_t size = 10;
    int *arr1 = malloc(size * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
        return 1;
    }

    printf("Avant ft_memset : ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    int value1 = 10;
    ft_memset(arr1, value1, size * sizeof(int));

    printf("Après ft_memset avec la valeur %d : ", value1);
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    // Test avec memset
    int *arr2 = malloc(size * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
        free(arr1); // Libérer la mémoire allouée par ft_memset
        return 1;
    }


    printf("Avant memset : ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr2[i]);
    printf("\n");


    int value2 = 10;
    memset(arr2, value2, size * sizeof(int));

    printf("Après natmemset avec la valeur %d : ", value2);
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    // Libération de la mémoire
    free(arr1);
    free(arr2);

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char test[10] = "";
	char *res = ft_memset(test, '\n', 1);
	printf("ft_ is : %s\n", res);
	char test2[10] = "";
	char *res2 = memset(test2, '\n', 1);
	printf("nat is : %s\n", res2);
}
*/