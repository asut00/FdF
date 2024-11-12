/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + start] != 0 && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[100] = "hello how are you doing";
	char *sub;

	sub = ft_substr(str, 2, 5);
	printf("res sub is : %s\n", sub);
}
*/

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char 	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + start] != 0 && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
*/