/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:40:12 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 21:12:42 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static char	is_in_str(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_trimmed_length(char const *s1, char const *set)
{
	size_t	length;
	int		i;

	length = ft_strlen(s1);
	i = length - 1;
	while (i > 0 && is_in_str(set, s1[i--]))
		length--;
	i = 0;
	while (length > 0 && is_in_str(set, s1[i++]))
		length--;
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	size_t			trimmed_length;
	unsigned int	i_trimmed;
	unsigned int	i_s1;

	trimmed_length = get_trimmed_length(s1, set);
	trimmed = malloc(sizeof(*trimmed) * (trimmed_length + 1));
	if (trimmed == 0)
		return (0);
	i_trimmed = 0;
	i_s1 = 0;
	while (s1[i_s1] && is_in_str(set, s1[i_s1]))
		i_s1++;
	while (i_trimmed < trimmed_length)
		trimmed[i_trimmed++] = s1[i_s1++];
	trimmed[i_trimmed] = 0;
	return (trimmed);
}
