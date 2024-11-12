/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	if (!s || !f)
		return (NULL);
	if (!*s)
		return (ft_strdup(""));
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <unistd.h>
#include <stdio.h>

char ft_putchar_spe(unsigned int i, char c)
{
	(void) i;	
	return (c + 1);
}

char f1(unsigned int i, char c)
{
	return(i + c);
}

int	main(void)
{
	//char str[] = "hello";
	//char res[] = ft_strmapi("", f1);
	printf("ft_ is : %s\n", ft_strmapi("", f1));
}
*/