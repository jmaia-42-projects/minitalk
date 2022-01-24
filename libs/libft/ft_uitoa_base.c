/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:44:22 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/02 16:07:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	uget_length(unsigned long long nb, int base)
{
	int					length;
	unsigned long long	temp_count;

	length = 0;
	temp_count = nb;
	while (temp_count != 0)
	{
		temp_count /= base;
		length++;
	}
	if (nb == 0)
		length = 1;
	return (length);
}

char	uget_char(int n, char *base)
{
	return (base[n]);
}

unsigned long long	upower(int x, int pow)
{
	unsigned long long	result;
	int					n;

	result = 1;
	n = 0;
	while (n++ < pow)
	{
		result *= x;
	}
	return (result);
}

unsigned char	*ufill_number(int nb_len, unsigned long long nb, char *base,
	int base_len)
{
	int				i;
	int				digit;
	int				str_len;
	unsigned char	*itoad;

	i = -1;
	str_len = nb_len + 1;
	itoad = malloc(sizeof(*itoad) * str_len);
	if (itoad == 0)
		return (0);
	while (++i < str_len - 1)
	{
		digit = nb / upower(base_len, nb_len - 1);
		itoad[i] = uget_char(digit, base);
		nb -= digit * upower(base_len, nb_len - 1);
		nb_len--;
	}
	itoad[i] = 0;
	return (itoad);
}

unsigned char	*ft_uitoa_base(unsigned long long nbr, char *base)
{
	int		origin_length;
	int		length_base;

	length_base = ft_strlen(base);
	origin_length = uget_length(nbr, length_base);
	return (ufill_number(origin_length, nbr, base, length_base));
}
