/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:23:56 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 21:06:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_cur;
	const char	*src_cur;

	if (!dest && !src)
		return (0);
	dest_cur = dest;
	src_cur = src;
	i = 0;
	while (i < n)
	{
		dest_cur[i] = src_cur[i];
		i++;
	}
	return (dest);
}
