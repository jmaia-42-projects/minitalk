/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:59:43 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/23 09:04:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cur;
	size_t			i;

	cur = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (cur[i] == (unsigned char) c)
			return (cur + i);
		i++;
	}
	return (0);
}
