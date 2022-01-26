/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annoying_0_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:18:25 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:46:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annoying_0_flag.h"

int	annoying_0_flag(t_options *options, unsigned char **raw_data)
{
	if (!has_flag(options->flags, FLAG_0_PAD)
		|| has_flag(options->flags, FLAG_PRECISION))
		return (0);
	options->precision = options->minimal_field_width
		- is_sign(*(raw_data[0]));
	return (apply_number_precision(options, raw_data));
}
