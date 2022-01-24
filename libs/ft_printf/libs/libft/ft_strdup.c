/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:07:14 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/24 12:12:28 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len_s;

	len_s = ft_strlen(s);
	dup = malloc(sizeof(*dup) * (len_s + 1));
	if (dup == 0)
		return (0);
	ft_memcpy(dup, s, sizeof(*dup) * (len_s + 1));
	return (dup);
}
