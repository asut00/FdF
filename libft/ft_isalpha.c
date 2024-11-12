/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/14 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90)
		|| (97 <= c && c <= 122))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	i;
	printf("enter int : ");
	scanf("%c", &i);	
	
	printf("ft_ is %d\n", ft_isalpha(i));
}
*/