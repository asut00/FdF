/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char charset)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0' && !(str[i] == charset))
			count_words++;
		while (str[i] != '\0' && !(str[i] == charset))
			i++;
	}
	return (count_words);
}

static int	ft_sl_s(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && !(str[i] == charset))
		i++;
	return (i);
}

static char	**free_tab(char **tab, int x)
{
	while (x >= 0)
	{
		free(tab[x]);
		x--;
	}
	free(tab);
	return (NULL);
}

static char	**attribute_words(char **tab, char const *str, char c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && !((str[i] == c)))
		{
			y = 0;
			tab[x] = malloc(((ft_sl_s(&str[i], c) + 1) * sizeof(char)));
			if (!tab[x])
				return (free_tab(tab, x));
			while (str[i] != '\0' && !(str[i] == c))
				tab[1][y++] = str[i++];
			tab[x++][y] = '\0';
		}
	}
	tab[x] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**tab;

	word_count = count_words(str, c);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = attribute_words(tab, str, c);
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{
	
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	char str2[] = "...salut.cava..";
	char charset2 = '.';
	char **split2;
	split2 = ft_split(str2, charset2);
	int i2 = 0;
	while(split2[i2] != 0)
	{
		printf("split2[%d] is : |%s|\n", i2, split2[i2]);
		i2++;
		//printf("%d", ft_charset_counter(str, charset));
	}
	printf("split2[%d] is : |%s|\n", i2, split2[i2]);


	printf("\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n");

	char str3[] = "salut...cava";
	char charset3 = '.';
	char **split3;
	split3 = ft_split(str3, charset3);
	int i3 = 0;
	while(split3[i3] != 0)
	{
		printf("split3[%d] is : %s\n", i3, split3[i3]);
		i3++;
		//printf("%d", ft_charset_counter(str, charset));
	}
	printf("split3[%d] is : %s\n", i3, split3[i3]);

	printf("\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
	
	char **tab;
	char str[] = "777hellof/ca//va/7//7moi///7foui77";
	char charset = '7';
	int	cw;

	cw = count_words(str, charset);
	printf("countwords is : %d\n", cw);

	tab = ft_split(str, charset);
	int x = 0;
	while (tab[x])
	{
		printf("tab[%d] : %s\n", x, tab[x]);
		x++;
	}
	printf("tab[%d] : %s\n", x, tab[x]);
}
*/