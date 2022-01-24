/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annoying_prec0val0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:09:44 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 14:06:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annoying_prec0val0.h"

int	annoying_prec0val0(t_options *options, unsigned char **raw_data)
{
	unsigned char	*new_data;

	if (has_flag(options->flags, FLAG_PRECISION) && options->precision == 0
		&& (*raw_data)[0] == '0')
	{
		new_data = (unsigned char *)ft_strdup("");
		if (!new_data)
			return (1);
		free(*raw_data);
		*raw_data = new_data;
	}
	return (0);
}
