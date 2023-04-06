/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:42 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/06 15:30:06 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_word(char const *str, char ch)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ch)
			i++;
		if (str[i] != ch && (str[i + 1] == ch || str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static int	size_word(char const *str, char ch)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ch)
	{
		j++;
		i++;
	}
	return (j);
}

static char	*copy(char *dest, const char *src, char ch)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != ch)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char		**tab_str;
	size_t			i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = nb_word(s, c);
	tab_str = malloc((k + 1) * sizeof(char *));
	if (!tab_str)
	{
		free(tab_str);
		return (0);
	}
	while (s[i] && j < k)
	{
		while (s[i] == c)
			i++;
		tab_str[j] = malloc(size_word(&s[i] + 1, c) * sizeof(char));
		if (!tab_str[j])
		{
			while (j >= 0)
			{
				free(tab_str[j]);
				j--;
			}
			free(tab_str);
			return (0);
		}
		copy(tab_str[j], &s[i], c);
		i += size_word(&s[i], c);
		j++;
		i++;
	}
	return (tab_str);
}

/*#include <stdio.h>

int main(void)
{
	char	**oui;
	int		i;

	i = 0;
	oui = ft_split("je suis une banane", ' ');
	while (oui[i])
	{
		printf("%s\n",oui[i]);
		i++;
	}
}
*/