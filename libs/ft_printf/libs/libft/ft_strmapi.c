/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:48:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 21:14:17 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len_s;
	char			*mapped;
	unsigned int	i;

	len_s = ft_strlen(s);
	mapped = malloc(sizeof(*mapped) * (len_s + 1));
	if (mapped == 0)
		return (0);
	i = 0;
	while (i < len_s)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = 0;
	return (mapped);
}
