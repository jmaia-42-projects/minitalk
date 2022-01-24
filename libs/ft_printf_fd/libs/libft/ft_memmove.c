/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:31:44 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/26 16:43:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_bytes;
	unsigned char	*dest_bytes;

	if (!dest && !src)
		return (0);
	src_bytes = (unsigned char *) src;
	dest_bytes = (unsigned char *) dest;
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			dest_bytes[i] = src_bytes[i];
	}
	else
	{
		i = n;
		while (i-- > 0)
			dest_bytes[i] = src_bytes[i];
	}
	return (dest);
}
