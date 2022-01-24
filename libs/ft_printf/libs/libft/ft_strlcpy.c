/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:33 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 08:45:56 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
	{
		if (size != 0 && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		src_len++;
	}
	if (size != 0)
	{
		dest[i] = 0;
		i++;
	}
	return (src_len);
}
