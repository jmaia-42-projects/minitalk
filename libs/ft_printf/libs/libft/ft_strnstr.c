/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:09:55 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 11:26:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		i_little;

	i = 0;
	i_little = 0;
	while (i < len && little[i_little] && big[i])
	{
		i_little = 0;
		while (i + i_little < len && big[i + i_little] == little[i_little]
			&& big[i + i_little])
			i_little++;
		if (little[i_little])
			i++;
	}
	if (little[i_little])
		return (0);
	return ((char *)&big[i]);
}
