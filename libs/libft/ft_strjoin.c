/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:35:32 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/24 13:39:43 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_join;
	char	*joined;
	int		i_s;
	int		i_joined;

	len_join = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(*joined) * (len_join + 1));
	if (joined == 0)
		return (0);
	i_s = 0;
	i_joined = 0;
	while (s1[i_s])
		joined[i_joined++] = s1[i_s++];
	i_s = 0;
	while (s2[i_s])
		joined[i_joined++] = s2[i_s++];
	joined[i_joined] = 0;
	return (joined);
}
