/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:14:04 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 21:12:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			len_s;
	int				potential_len;
	char			*sub;
	unsigned int	i_s;
	unsigned int	i_sub;

	len_s = ft_strlen(s);
	potential_len = (len_s - start);
	potential_len *= (potential_len > 0);
	if ((size_t) potential_len > len)
		sub = malloc(sizeof(*sub) * (len + 1));
	else
		sub = malloc(sizeof(*sub) * (potential_len + 1));
	if (sub == 0)
		return (0);
	i_s = start;
	i_sub = 0;
	while (i_s < start + len && i_s < len_s)
		sub[i_sub++] = s[i_s++];
	sub[i_sub] = 0;
	return (sub);
}
//
//int main()
//{
//	ft_substr("tripouille", 100, 1);
//}
