/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:46:37 by edfirmin          #+#    #+#             */
/*   Updated: 2023/04/04 15:41:00 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)s1;
	while (str[i])
		j++;
	//if (str[i] == set)
	//	str = &str[i];
	if (str[--j] == set)
		str[j] = 0;
	return (str);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("jdrfgfefj", 'j'));
}