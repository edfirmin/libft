/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:42 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/06 10:23:15 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strcpy(char *dest, char const *src, char ch)
{
	int	i;

	i = 0;
	while (src[i] != ch)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_str;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	tab_str = 0;
	while (s[i])
	{
		n = 0;
		s = &s[i];
		while (s[i] != c)
		{
			i++;
			n++;
		}
		tab_str[j] = malloc((n + 1) * sizeof(char));
		strcpy(tab_str[j], s, c);
		j++;
		i++;
	}
	return (tab_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**oui;

	oui = ft_split("je suis une mangue :)", 'u');
	printf("%s\n", oui[0]);
}*/